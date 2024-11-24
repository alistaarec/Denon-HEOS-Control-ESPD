/*HEOS TFT Widget Denon ESPD
Based on HEOS / Denon AVR Library by: janphoffmann https://github.com/janphoffmann/ESP32-Heos-Control
ESPD 1.0 Shield by Laskakit.cz

*/
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <NTPClient.h>
#include <SD.h>

//Denon dependencies
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#include <functional>
#include <ArduinoJson.h>
#include "DenonAVR.h"
#include "heosControl.h"
#include "commands.h"  

//lvgl
#include <lvgl.h>
#include "ui.h"


heosControl HEOS; 
IPAddress HeosIP(10,101,50,175);


File sdFile;


// Wi-Fi credentials
char ssid_char[20];
char pass_char[20];
const char* ssid;
const char* pass;
const char* filename = "/wifi.txt";

unsigned long lastTime;
unsigned long lastTimeSec;
unsigned long lastHeosUpd;
unsigned long lastActTimeSong;
unsigned long lastAnimSwitch;
int updtDisplayNTP   = 60000;
int updtDisplaySec   = 900;
int updHeos          = 10000;
int ActTimeSong      = 1000;
int animSwitch       = 30000;

int durationInS = 0;
int durationInSold = 0;
bool longMode = true;
bool playingAct = false;


uint16_t calData[5];

#define TFT_HOR_RES   240
#define TFT_VER_RES   320
#define TFT_ROTATION  LV_DISPLAY_ROTATION_90


/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 50 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

TFT_eSPI tft = TFT_eSPI( TFT_HOR_RES, TFT_VER_RES );

// TFT SPI
#define LCD_LED          33      // TFT backlight pin
int lcd_led_PWM =        100;

#define SD_CS_PIN     4
#define MOSI  13
#define MISO  12
#define SCK   14

// NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "0.cz.pool.ntp.org", 3600, 60000); // Czech NTP server

void updateTimeRead();


void my_disp_flush( lv_display_t *disp, const lv_area_t *area, uint8_t * px_map)
{
    lv_display_flush_ready(disp);
}

//Touch Readings
void my_touchpad_read( lv_indev_t * indev, lv_indev_data_t * data )
{
    
    uint16_t touchX = 0, touchY = 0;

    bool touched = tft.getTouch( &touchX, &touchY, 600 );

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        //touchX= TFT_HOR_RES  - touchX;
        touchX= TFT_VER_RES - touchX;

        data->point.x = touchY;
        data->point.y = touchX;

        Serial.print( "Data x " );
        Serial.println( touchX );

        Serial.print( "Data y " );
        Serial.println( touchY );
    }
    
}


//millis() as tick source*//
static uint32_t my_tick(void)
{
    return millis();
}

//---------------Touch Events------------//

void playBtnDen(lv_event_t * e)
{
	HEOS.DenonPlay();
  Serial.println("Denon Play");
  playingAct = true;
}

void stopBtnDen(lv_event_t * e)
{
	HEOS.DenonStop();
  Serial.println("Denon Stop");
  playingAct = false;
}

void fwBtnDen(lv_event_t * e)
{
	HEOS.DenonNext();
  Serial.println("Denon Next");
  updateTimeRead();
}

void rwBtnDen(lv_event_t * e)
{
	HEOS.DenonPrev();
  Serial.println("Denon Prev");
  updateTimeRead();
}

void hiddenServiceMenu(lv_event_t * e)
{
  lv_slider_set_value(ui_backlitSld, lcd_led_PWM, LV_ANIM_OFF);
  lv_scr_load(ui_Screen2);
}

void lcdSetBacklight(lv_event_t * e)
{
  
	lcd_led_PWM = lv_slider_get_value(ui_backlitSld);
  analogWrite(LCD_LED, lcd_led_PWM);
}

void calDisplay(lv_event_t * e)
{
	
}

void saveBackMain(lv_event_t * e)
{
	lv_scr_load(ui_Screen1);
  HEOS.updateMedia();
}


//--------------------------DENON CALLBACKS--------------------------------//
 
//Station or service
void newStationCb(const char *data, size_t len){  
  Serial.print("new Station received:");  
  Serial.println(data);
  lv_label_set_text(ui_albumLbl, data); 
}  
  
//Artist
void newArtistCb(const char *data,size_t len){  
  Serial.print("Playing Artist: ");  
  Serial.println(data);
  lv_label_set_text(ui_artistLbl, data);
  
}  
  
//Title
void newSongCb(const char *data,size_t len){  
  Serial.print("Playing Song: ");  
  Serial.println(data);
  lv_label_set_text(ui_songLbl, data);
  
}  

// for everything that heos is answering:  
// inside this you have all the time in the world as it is updated in the run() function  
void HeosResponseCb(const char* data,size_t len){  
  Serial.print("Heos texted: ");  
  Serial.println(data);
  updateTimeRead();
}  
//--------------------------END DENON CALLS--------------------------------//


void SDinit(){ //SD Card Init
  SD.begin(SD_CS_PIN);
}

void saveCredentialsToSD(const char* ssid, const char* password) { //Saving WiFi to SD
  sdFile = SD.open(filename, FILE_WRITE);
  if (sdFile) {
    sdFile.println(ssid);
    sdFile.println(password);
    sdFile.close();
    Serial.println("Credentials written to SD card.");
  } else {
    Serial.println("Error opening file to write credentials.");
  }
}

void loadWiFiCred() { //Loading WiFi from SD

  if (SD.exists(filename)) {
    // Read credentials from SD card
    sdFile = SD.open(filename, FILE_READ);
    if (sdFile) {
      String ssidStr = sdFile.readStringUntil('\n');
      String passwordStr = sdFile.readStringUntil('\n');
      //ssidStr.trim();  // Remove any whitespace
      //passwordStr.trim();
      
      ssidStr.toCharArray(ssid_char, ssidStr.length());
      passwordStr.toCharArray(pass_char, passwordStr.length());
      
      Serial.println("Credentials loaded from SD card.");
      sdFile.close();
    }
  } else {
    // File doesn't exist, save default credentials
    ssid = "Alistar_Turris_2G";
    pass = "8BDZL3GQ59";
    saveCredentialsToSD(ssid, pass);
    Serial.println("Default credentials saved to SD card.");
  }
}

void NTP_Update(){ //Update NTP Data

  timeClient.update();
}

void disp_update_time(){ //Update time on TFT

  char buf[13];
  //timeClient.update();
  sprintf(buf, "%02d:%02d:%02d", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
  lv_label_set_text(ui_timeLbl, buf);
  lv_label_set_text(ui_timeLbl2, buf);
}


void wifiInit() //Init WiFi
{
  Serial.println(ssid_char);
  Serial.println(pass_char);
  WiFi.begin(ssid_char, pass_char);
  Serial.print("Connecting.");
 
  while ( WiFi.status() != WL_CONNECTED ) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("connected");
}


void lvgl_init_func(){ //Init lvgl
    lv_init();
    lv_tick_set_cb( my_tick );

             /* TFT init */
    lv_display_t * disp;
    /*TFT_eSPI can be enabled lv_conf.h to initialize the display in a simple way*/
    disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
    lv_display_set_rotation(disp, TFT_ROTATION);

    static lv_indev_t* indev;
    indev = lv_indev_create();
    lv_indev_set_type( indev, LV_INDEV_TYPE_POINTER );
    lv_indev_set_read_cb( indev, my_touchpad_read );

    ui_init();
}

void updateTimeAct(){ //Actual song update every second
  durationInS ++;
  int durationMinutes = durationInS / 60;
  int durationS = 60;
  char timetrack[6];
  sprintf(timetrack, "%02d:%02d", durationMinutes, durationInS % durationS);
  lv_label_set_text(ui_actSongTime, timetrack);
  lv_bar_set_value(ui_songProgress, durationInS, LV_ANIM_OFF);
}

void updateTimeRead(){ //Update reading of time from HEOS to synch actual song time 

  durationInS = HEOS.actTrackTime; //Seconds
  if(durationInS != durationInSold){
    int durationMinutes = durationInS / 60;
    int durationS = 60;
    char timetrack[6];
    sprintf(timetrack, "%02d:%02d", durationMinutes, durationInS % durationS);
    lv_label_set_text(ui_actSongTime, timetrack);
    durationInSold = durationInS;
    playingAct = true;
  }
  else {
    playingAct = false;
  }

  int totdurationInS = HEOS.trackTime; //Minutes
  int totdurationMinutes = totdurationInS / 60;
  int durationS = 60;
  char timetrack[6];
  sprintf(timetrack, "%02d:%02d", totdurationMinutes, totdurationInS % durationS);
  lv_label_set_text(ui_songTime, timetrack);
  lv_bar_set_range(ui_songProgress, 0 , totdurationInS);
  lv_bar_set_value(ui_songProgress, durationInS, LV_ANIM_OFF);
}


void setup(){

Serial.begin(115200);

analogWrite(LCD_LED, lcd_led_PWM);

SPI.begin(SCK, MISO, MOSI); //Setup SPI here for proper function

tft.begin(); 
tft.init();
tft.fillScreen(TFT_BLACK);
tft.setRotation(1);
tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);  //Display Calibration every start, don't have saving cal data complete yet

  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }
tft.setTouch(calData); //set cal data 


lvgl_init_func();
delay(10);
SDinit();
delay(100);
loadWiFiCred();
delay(100);
wifiInit();
delay(100);

  //attatch HEOS Callbacks 
HEOS.onNewStation(newStationCb);  
HEOS.onNewArtist(newArtistCb);  
HEOS.onNewSong(newSongCb);  
HEOS.onHeosResponse(HeosResponseCb); 
  

  //begin function with known IP  
HEOS.begin(HeosIP);                   //connect to HEOS and turn on subscription of data 
  //or with friendlyName  
  //HEOS.begin(FrienldyName);  

HEOS.updateMedia();  //updating data from HEOS for first time

delay(500);
Serial.println( "Setup done" );
lv_scr_load(ui_Screen1); //load lvgl Screen


}

void loop() {

//unsigned long start = micros();

HEOS.run();  

  if (millis() > lastTime + updtDisplayNTP)  
  {
    NTP_Update();
    HEOS.updateMedia();                                                       //For now, because subscription is not that reliable
    lastTime = millis();
  }

  if (millis() > lastTimeSec + updtDisplaySec)  
  {
    disp_update_time();
    lastTimeSec = millis();
  }

  if (millis() > lastHeosUpd + updHeos)  
  {
    //HEOS.updateMedia();                                                           //update data from HEOS periodicly, but need to figure, why subscription not working reliably
    
    if(longMode == true){                                                         //Scrolling long text for a few seconds, repeated every 30s
      lv_label_set_long_mode(ui_songLbl, LV_LABEL_LONG_SCROLL_CIRCULAR);
      lv_label_set_long_mode(ui_artistLbl, LV_LABEL_LONG_SCROLL_CIRCULAR);
      lv_label_set_long_mode(ui_albumLbl, LV_LABEL_LONG_SCROLL_CIRCULAR);
      longMode = false;
    }
    else {
      lv_label_set_long_mode(ui_songLbl, LV_LABEL_LONG_DOT);
      lv_label_set_long_mode(ui_artistLbl, LV_LABEL_LONG_DOT);
      lv_label_set_long_mode(ui_albumLbl, LV_LABEL_LONG_DOT);
      
    }
    lastHeosUpd = millis();
  }

  HEOS.run();  

  if (playingAct == true){
    if (millis() > lastActTimeSong + ActTimeSong)                                 //actual song time update +1s
    {
      updateTimeAct();
      lastActTimeSong = millis();
    }
  }
  if (millis() > lastAnimSwitch + animSwitch)                                     //only animation timer
  {
    longMode = true;
    lastAnimSwitch = millis();
  }


  HEOS.run();                                                                     //HEOS update in loop

  lv_timer_handler();                                                             //lvgl update in loop
  //delay(5);  
  
  //unsigned long end = micros();
  //unsigned long delta = end - start;                                                                      //dunno why, for fun 
  //Serial.println(delta);  
}



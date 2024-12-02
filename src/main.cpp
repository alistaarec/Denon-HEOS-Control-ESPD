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
//#include "DenonAVR.h"
#include "heosControl.h"
#include "commands.h"  

//lvgl
#include <lvgl.h>
#include "ui/ui.h"


heosControl HEOS; 
IPAddress HeosIP(0,0,0,0);
const char* HeosIP_char;
char HeosIP_charr[30];


File sdFile;


// Wi-Fi credentials
char ssid_char[20];
char pass_char[20];
const char* ssid;
const char* pass;
//files on SD
const char* wifiFile = "/wifi.txt";
const char* touchFile = "/touchCal.txt";
const char* settings = "/settings.txt";

unsigned long lastTime;
unsigned long lastTimeSec;
unsigned long lastHeosUpd;
unsigned long lastActTimeSong;
unsigned long lastAnimSwitch;
unsigned long lastRebootTime;
int updtDisplayNTP   = 60000;
int updtDisplaySec   = 900;
int updHeos          = 10000;
int ActTimeSong      = 1000;
int animSwitch       = 30000;
int rebootTimer      = 10000;

int durationInS = 0;
int durationInSold = 0;
bool longMode = true;
bool playingAct = false;
bool allSet = false;
bool wifiSet = false;
bool sdSet = false;
bool heosSet = false;
bool wifiLoad = false;
bool wifiManager = false;
bool connTimeout = false;
bool calSet = false;
bool settingsSet = false;
bool rebootESP = false;
bool otherSettings = false;
bool useIP = true;

int wifiTimeout = 0; 

#define WIFI_MAX_SSID  (7u)
static char wifi_dd_list[WIFI_MAX_SSID*20] = { 0 };


uint16_t calData[5];

#define TFT_HOR_RES   240
#define TFT_VER_RES   320
#define TFT_ROTATION  LV_DISPLAY_ROTATION_90


/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 120 * (LV_COLOR_DEPTH / 8))
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
void calibrateTouchPanel();
void WiFi_ScanSSID();
void saveCredentialsToSD(const char* ssid, const char* password);
void loadCalibrationSD();
void saveCalibrationSD(uint16_t *calData);
void saveConfigSD(int lcd_led_PWM, const char* HeosIP_char);
void loadConfigSD();



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

  calibrateTouchPanel();
}

void saveBackMain(lv_event_t * e)
{
  saveConfigSD(lcd_led_PWM, HeosIP_charr);
	lv_scr_load(ui_Screen1);
  HEOS.updateMedia();
}

void scanWifi(lv_event_t * e)
{
	WiFi_ScanSSID();
}

void connWifi(lv_event_t * e)
{
  lv_dropdown_get_selected_str(ui_ssidDrop, ssid_char, 0);
  pass = lv_textarea_get_text(ui_passTxtbox);
  
  
	saveCredentialsToSD(ssid_char, pass);

  delay(2000);

  lv_scr_load(ui_ScreenReboot);
  rebootESP = true;
  lastRebootTime = millis();
  lv_timer_handler();
  

}

void heosSetup(lv_event_t * e)
{
	otherSettings = true;
  lv_scr_load(ui_Screen5);
  lv_timer_handler();
  lv_textarea_set_text(ui_heosIPTxt, HeosIP_charr);

}

void rbtSetting(lv_event_t * e)
{
	lv_scr_load(ui_ScreenReboot);
  rebootESP = true;
  lastRebootTime = millis();
  lv_timer_handler();
}

void wifiSetup(lv_event_t * e)
{
	wifiManager = true;
  lv_scr_load(ui_Screen4); //load lvgl Screen
  lv_timer_handler();
}

void heosSave(lv_event_t * e)
{
  const char* s;
	s = lv_textarea_get_text(ui_heosIPTxt);
  saveConfigSD(lcd_led_PWM, s);
  lv_scr_load(ui_ScreenReboot);
  rebootESP = true;
  lastRebootTime = millis();
  lv_timer_handler();

}

void rbtespNow(lv_event_t * e)
{
	lv_scr_load(ui_ScreenReboot);
  rebootESP = true;
  lastRebootTime = millis();
  lv_timer_handler();
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
  Serial.print("PID: ");
  Serial.println(HEOS.pid);
  Serial.println(HEOS.pidCheck);
  updateTimeRead();
}  
//--------------------------END DENON CALLS--------------------------------//


void SDinit(){ //SD Card Init
  if(!SD.begin(SD_CS_PIN)){
    lv_label_set_text(ui_sdLbl, "SD Init Err.. Check SD Card and Reset device");
    lv_timer_handler();
    delay(5000);
  }
  else {
    lv_label_set_text(ui_sdLbl, "SD Init OK..");
    lv_timer_handler();
    sdSet = true;
  }

}

void saveCredentialsToSD(const char* ssid, const char* password) { //Saving WiFi to SD
  sdFile = SD.open(wifiFile, FILE_WRITE);
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

  if (SD.exists(wifiFile)) {
    // Read credentials from SD card
    sdFile = SD.open(wifiFile, FILE_READ);
    if (sdFile) {
      String ssidStr = sdFile.readStringUntil('\n');
      String passwordStr = sdFile.readStringUntil('\n');
      //ssidStr.trim();  // Remove any whitespace
      //passwordStr.trim();
      
      ssidStr.toCharArray(ssid_char, ssidStr.length());
      passwordStr.toCharArray(pass_char, passwordStr.length());
      lv_label_set_text(ui_wifLoadLbl, "WiFi Data OK..");
      lv_timer_handler();
      Serial.println("Credentials loaded from SD card.");
      sdFile.close();
      wifiLoad = true;
    }
  } else {
    lv_label_set_text(ui_wifLoadLbl, "WiFi Data Err..");
    lv_timer_handler();
    // File doesn't exist, save default credentials
    //ssid = "Alistar_Turris_2G";
    //pass = "8BDZL3GQ59";
    //saveCredentialsToSD(ssid, pass);
    //Serial.println("Default credentials saved to SD card.");
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
  WiFi.disconnect();
  Serial.println(ssid_char);
  Serial.println(pass_char);
  Serial.print("Connecting.");
  lv_label_set_text(ui_wifConLbl, "Connecting..");
  lv_timer_handler();
  WiFi.begin(ssid_char, pass_char);
  delay(10000);
  if (WiFi.status() == WL_CONNECTED){
      Serial.println("connected");
      lv_label_set_text(ui_wifConLbl, "Connected !");
      lv_timer_handler();
      wifiSet = true;
    }
  if (WiFi.status() != WL_CONNECTED) {
      lv_label_set_text(ui_wifConLbl, "Failed to Connect..");
      lv_timer_handler();
      WiFi.disconnect();
      delay(5000);      
      wifiManager = true;
      lv_scr_load(ui_Screen4); //load lvgl Screen
      lv_timer_handler();
    }
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

void calibrateTouchPanel(){

  tft.fillScreen(TFT_BLACK);
  tft.calibrateTouch(calData, TFT_ORANGE, TFT_BLACK, 15);  //Display Calibration every start, don't have saving cal data complete yet

  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }
tft.setTouch(calData); //set cal data
saveCalibrationSD(calData);
lv_scr_load(ui_Screen1);
lv_timer_handler();
lv_scr_load(ui_Screen2);

}

void calibrateTouchPanelfromBoot(){

  tft.fillScreen(TFT_BLACK);
  tft.calibrateTouch(calData, TFT_ORANGE, TFT_BLACK, 15);  //Display Calibration every start, don't have saving cal data complete yet

  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }
tft.setTouch(calData); //set cal data
saveCalibrationSD(calData);
lv_scr_load(ui_ScreenReboot);
rebootESP = true;
lastRebootTime = millis();
lv_timer_handler();



}

void WiFi_ScanSSID()
{
  lv_dropdown_clear_options(ui_ssidDrop);
  lv_timer_handler();
  String ssid_name;
  Serial.println("Start Scanning");
  lv_dropdown_clear_options(ui_ssidDrop);
  lv_dropdown_add_option(ui_ssidDrop, "Scanning..", 0);
  lv_timer_handler();
  int n = WiFi.scanNetworks();
  Serial.println("Scanning Done");
  if( n == 0 )
  {
    Serial.println("No Networks Found");
    lv_dropdown_clear_options(ui_ssidDrop);
    lv_dropdown_add_option(ui_ssidDrop, "No Networks", 0);
    lv_timer_handler();
  }
  else
  {
    // I am restricting n to max WIFI_MAX_SSID value
    n = n <= WIFI_MAX_SSID ? n : WIFI_MAX_SSID;
    for (int i = 0; i < n; i++) 
    {
      if( i == 0 )
      {
        ssid_name = WiFi.SSID(i);
      }
      else
      {
        ssid_name = ssid_name + WiFi.SSID(i);
      }
      ssid_name = ssid_name + '\n';
      delay(10);
    }
    // clear the array, it might be possible that we coming after rescanning
    memset( wifi_dd_list, 0x00, sizeof(wifi_dd_list) );
    strcpy( wifi_dd_list, ssid_name.c_str() );
    Serial.println(wifi_dd_list);
    lv_dropdown_clear_options(ui_ssidDrop);
    lv_dropdown_set_options(ui_ssidDrop, wifi_dd_list);
    lv_timer_handler();

  }
  Serial.println("Scanning Completed");
}

void saveCalibrationSD(uint16_t *calData) {

  sdFile = SD.open(touchFile, FILE_WRITE);
  if (!sdFile) {
    Serial.println("Failed to open file for writing");
    return;
  }

  for (int i = 0; i < 5; i++) {
    sdFile.println(calData[i]);  // Write each calibration value to the file
  }
  sdFile.close();
  Serial.println("Calibration data saved to SD card.");
}

void loadCalibrationSD(){
    sdFile = SD.open(touchFile);
  if (!sdFile) {
    Serial.println("Calibration file not found.");
    lv_label_set_text(ui_calLoadLbl, "No touch data, calibration will start...");
    lv_timer_handler();
    delay(3000);
    tft.fillScreen(TFT_DARKGREY);
    calibrateTouchPanelfromBoot();
    return;
  }

  uint16_t calData[5];
  bool isValid = true;
  // Read data from the file
  for (int i = 0; i < 5; i++) {
    String line = sdFile.readStringUntil('\n');
    if (line.length() == 0) {  // Check for a blank line (file is incomplete)
      isValid = false;
      break;
    }
    calData[i] = line.toInt();
    if (calData[i] == 0) {  // Detect if any data is 0 (might indicate invalid calibration)
      isValid = false;
    }
  }
  sdFile.close();

  if(!isValid) {
    lv_label_set_text(ui_calLoadLbl, "Invalid data, calibration will start...");
    lv_timer_handler();
    delay(2000);
    calibrateTouchPanelfromBoot();
  }
  else{
    tft.setTouch(calData);  // Apply the calibration data
    Serial.println("Calibration data OK..");
    lv_label_set_text(ui_calLoadLbl, "Calibration data OK..");
    lv_timer_handler();
    calSet = true;
    delay(2000);

  }

}

void saveConfigSD(int lcd_led_PWM, const char* HeosIP_char){
  sdFile = SD.open(settings, FILE_WRITE);
  if(!sdFile) {
    Serial.println("Failed to open settings file for writing");
    return;
  }
  if (sdFile){
    sdFile.println(lcd_led_PWM);
    sdFile.println(HeosIP_char);
    sdFile.close();
    Serial.println("Settings Saved!");
  }
  else {
    Serial.println("Error saving settings");
  }
}

void loadConfigSD(){
    sdFile = SD.open(settings);
  if (sdFile) {
    Serial.println("Reading data from settings:");
    lv_label_set_text(ui_settingsLoadLbl, "Loading Settings SD..");

    if (sdFile.available()) {
      lcd_led_PWM = sdFile.readStringUntil('\n').toInt();
    }
    if (sdFile.available()) {
      String addrString = sdFile.readStringUntil('\n');
      addrString.toCharArray(HeosIP_charr, addrString.length());
    }
    sdFile.close();

    Serial.print("LCD_PWM: ");
    Serial.println(lcd_led_PWM);
    analogWrite(LCD_LED, lcd_led_PWM);
    Serial.print("HeosIP: ");
    Serial.println(HeosIP_charr);
    lv_label_set_text(ui_settingsLoadLbl, "Loading Settings OK..");


    if (HeosIP.fromString(HeosIP_charr)) {
    // Successfully converted to IPAddress
    Serial.print("Converted IPAddress: ");
    Serial.println(HeosIP);
  } else {
    // Conversion failed
    Serial.println("Invalid IP address format!");
  }


    settingsSet = true;
  } else {
    Serial.println("Error opening file for reading.");
    lv_label_set_text(ui_settingsLoadLbl, "Loading Settings Err..");
  }
}


void setup(){

Serial.begin(115200);

analogWrite(LCD_LED, lcd_led_PWM);

SPI.begin(SCK, MISO, MOSI); //Setup SPI here for proper function

tft.begin(); 
tft.init();
tft.setRotation(1);

lvgl_init_func();

lv_scr_load(ui_Screen3); //load lvgl Screen

lv_timer_handler();

  //attatch HEOS Callbacks 
HEOS.onNewStation(newStationCb);  
HEOS.onNewArtist(newArtistCb);  
HEOS.onNewSong(newSongCb);  
HEOS.onHeosResponse(HeosResponseCb); 

}

void loop() {

//unsigned long start = micros();

HEOS.run();

if (allSet == true && wifiManager == false && rebootESP == false && otherSettings == false) {

  if (millis() > lastTime + updtDisplayNTP)  
  {
    NTP_Update();
    HEOS.updateMedia();                                                       //For now, because subscription is not that reliable
    lastTime = millis();
  }

  if (playingAct == true){
    if (millis() > lastActTimeSong + ActTimeSong)                                 //actual song time update +1s
    {
      updateTimeAct();
      lastActTimeSong = millis();
    }
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

    if (millis() > lastAnimSwitch + animSwitch)                                     //only animation timer
  {
    longMode = true;
    lastAnimSwitch = millis();
  }

    if (millis() > lastTimeSec + updtDisplaySec)  
  {
    disp_update_time();
    lastTimeSec = millis();
  }

}


if (allSet == false && wifiManager == false && rebootESP == false && otherSettings == false) {
    if (sdSet == false) {
      lv_timer_handler();
      lv_label_set_text(ui_sdLbl, "SD Init");
      lv_timer_handler();
      SDinit();
      delay(1500);
    }
    if (sdSet == true && calSet == false && rebootESP == false){
      lv_label_set_text(ui_calLoadLbl, "Loading Calibration Data..");
      lv_timer_handler();
      loadCalibrationSD();
      delay(1500);
    }
    if (sdSet == true && settingsSet == false && rebootESP == false){
      lv_label_set_text(ui_settingsLoadLbl, "Loading Settings..");
      lv_timer_handler();
      loadConfigSD();
      delay(1500);
      
    }
    if (sdSet == true && wifiLoad == false && rebootESP == false) {
      lv_label_set_text(ui_wifLoadLbl, "Loading WiFi Data..");
      lv_timer_handler();
      loadWiFiCred();
      delay(1500);
    }
    if (wifiLoad == true && wifiSet == false && rebootESP == false){
      lv_label_set_text(ui_wifConLbl, "Connecting to WiFi");
      lv_timer_handler();
      wifiInit();
      delay(1500);
      lv_timer_handler();
      //lv_scr_load(ui_Screen1);
    }
    if (wifiSet == true && heosSet == false && rebootESP == false){

      if(useIP == true){
        HEOS.begin(HeosIP);
      }
      //connect to HEOS and turn on subscription of data 
      lv_label_set_text(ui_heosLbl, "Connecting to HEOS");
      lv_timer_handler();  
      HEOS.updateMedia();  //updating data from HEOS for first time
      heosSet = true;
      Serial.println( "Setup done" );
      lv_scr_load(ui_Screen1);
      
      allSet = true;
    }
  }

  if(rebootESP == true){
    if (millis() > lastRebootTime + rebootTimer){
      ESP.restart();
    } 
  }
  



  HEOS.run();                                                                     //HEOS update in loop

  lv_timer_handler();                                                             //lvgl update in loop 
  
  //unsigned long end = micros();
  //unsigned long delta = end - start;                                                                      //dunno why, for fun 
  //Serial.println(delta);  
}



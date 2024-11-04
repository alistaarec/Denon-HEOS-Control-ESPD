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


heosControl HEOS; 
IPAddress IP(10,101,50,174);


File sdFile;


// Wi-Fi credentials
char ssid_char[100];
char pass_char[100];
const char* ssid;
const char* pass;
const char* filename = "/wifi.txt";

unsigned long lastTime;
unsigned long lastTimeSec;
unsigned long lastHeosUpd;
int updtDisplayNTP   = 60000;
int updtDisplaySec   = 500;
int updHeos          = 5000;

#define TFT_DISPLAY_RESOLUTION_X  320
#define TFT_DISPLAY_RESOLUTION_Y  480

// TFT SPI
#define TFT_LED          33      // TFT backlight pin
#define TFT_LED_PWM      100     // dutyCycle 0-255 last minimum was 15

#define SD_CS_PIN 4

String artistTxt;
String songTxt;
String stationTxt;

int updateData = 1;

int msg;
// NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "0.cz.pool.ntp.org", 3600, 60000); // Czech NTP server

TFT_eSPI tft = TFT_eSPI();

//--------------------------DENON CALLBACKS--------------------------------//
//for getting info about a Radiostation or Spotify or Tidal  
void newStationCb(const char *data, size_t len){  
  Serial.print("new Station received:");  
  Serial.println(data);
  if(stationTxt != data){
    stationTxt = data;
    updateData = 1; 
  }
}  
  
//for info about the artist  
void newArtistCb(const char *data,size_t len){  
  Serial.print("Playing Artist: ");  
  Serial.println(data);
  if(artistTxt != data){
    artistTxt = data;
    updateData = 1; 
  }
}  
  
//for info about the song  
void newSongCb(const char *data,size_t len){  
  Serial.print("Playing Song: ");  
  Serial.println(data);
  if(songTxt != data){
    songTxt = data;
    updateData = 1;
  }
}  

// for everything that heos is answering:  
// inside this you have all the time in the world as it is updated in the run() function  
void HeosResponseCb(const char* data,size_t len){  
  Serial.print("Heos texted: ");  
  Serial.println(data);
   
}  
//--------------------------END DENON CALLS--------------------------------//

void blankLoop() {
  delay(2000);
  blankLoop();
}

void dispMsg(){
tft.fillScreen(TFT_BLACK);
tft.setTextFont(4);
tft.setTextColor(TFT_YELLOW, TFT_BLACK, true);
tft.setCursor(10, 10);

    switch (msg) {
      case 0:
      tft.print("Loading SD...");
      delay(1000);
      break;
      case 1:
      tft.println("Error Loading SD");
      tft.print("Reset and try again..");
      blankLoop();
      break;
      case 2:
      tft.println("Loading Configuration");
      tft.print  ("    Please Wait...");
      delay(1000);
      break;
      case 3:
      tft.print("Connecting to: ");
      tft.print(ssid);
      delay(1000);
      break;
      case 4:
      tft.println("WiFi Connected");
      tft.print("IP: ");
      tft.print(WiFi.localIP());
      delay(1000);
      break;
    }
    
}

void SDinit(){
  if (!SD.begin(SD_CS_PIN)){
    msg = 1;
    dispMsg();
    return;
  }
  else {
    msg = 0;
    dispMsg();
  }
}

void saveCredentialsToSD(const char* ssid, const char* password) {
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

void loadWiFiCred() {

    msg = 2;
    dispMsg();

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

void NTP_Update(){

  //tft.fillScreen(TFT_BLACK);
  tft.setCursor(400, 1);
  tft.setTextColor(TFT_YELLOW, TFT_DARKGREY, true);
  tft.setTextFont(2);  
  char buffer[13];
  timeClient.update();
  sprintf(buffer, "%02d:%02d:%02d", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
  tft.print(buffer);
}

void disp_update(){

  if(updateData == 1){
    tft.fillScreen(TFT_BLACK);
  }
  tft.fillRect(0, 0, 480, 20, TFT_DARKGREY);
  
  tft.setCursor(400, 1);
  tft.setTextColor(TFT_YELLOW, TFT_DARKGREY, true);
  tft.setTextFont(2);  
  char buffer[13];
  //timeClient.update();
  sprintf(buffer, "%02d:%02d:%02d", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
  tft.print(buffer);

  if(updateData == 1) {
    
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
    tft.setTextFont(4);
    tft.setCursor(40, 70);
    tft.print(stationTxt);
    tft.setCursor(40, 110);
    tft.print(artistTxt);
    tft.setCursor(40, 145);
    tft.print(songTxt);
    
    //tft.drawLine(0, 150, 480, 150,TFT_RED );

    updateData = 0;
  }
}

void displayInit()
{
	// configure backlight LED PWM functionalitites
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);
  
  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
}

void wifiInit()
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

void setup(){

Serial.begin(115200);
delay(10);
displayInit();
delay(10);
SDinit();
delay(100);
loadWiFiCred();
delay(100);
wifiInit();
delay(2000);
tft.fillScreen(TFT_BLACK);

  //attatch the callbacks  
HEOS.onNewStation(newStationCb);  
HEOS.onNewArtist(newArtistCb);  
HEOS.onNewSong(newSongCb);  
HEOS.onHeosResponse(HeosResponseCb); 
  

  //begin function with known IP  
HEOS.begin(IP);  
  //or with friendlyName  
  //HEOS.begin(FrienldyName);  

HEOS.updateMedia(); 

delay(3000);

}

void loop() {
  if (millis() > lastTime + updtDisplayNTP)  
  {
    NTP_Update();
    lastTime = millis();
  }

    if (millis() > lastTimeSec + updtDisplaySec)  
  {
    disp_update();
    lastTimeSec = millis();
  }

    if (millis() > lastHeosUpd + updHeos)  
  {
     
    lastHeosUpd = millis();
  }

  HEOS.run(); 
}



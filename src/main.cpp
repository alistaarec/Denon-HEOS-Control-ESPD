#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <NTPClient.h>
#include <SD.h>

File sdFile;


// Wi-Fi credentials
char ssid_char[100];
char pass_char[100];
const char* ssid;
const char* pass;
const char* filename = "/wifi.txt";

unsigned long lastTime;
unsigned long lastTimeSec;
int updtDisplayNTP   = 60000;
int updtDisplaySec   = 500;

#define TFT_DISPLAY_RESOLUTION_X  320
#define TFT_DISPLAY_RESOLUTION_Y  480

// TFT SPI
#define TFT_LED          33      // TFT backlight pin
#define TFT_LED_PWM      100     // dutyCycle 0-255 last minimum was 15

#define SD_CS_PIN 4

int msg;
// NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "0.cz.pool.ntp.org", 3600, 60000); // Czech NTP server

TFT_eSPI tft = TFT_eSPI();

void blankLoop() {
  delay(2000);
  blankLoop();
}

void dispMsg(){


    switch (msg) {
      case 0:
      tft.print("Loading SD...");
      delay(1000);
      break;
      case 1:
      tft.println("Error Loading SD");
      tft.print("Reset and try again..");
      delay(1000);
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
  tft.setCursor(40, 120);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK, true);

  tft.setTextFont(8);  

  char buffer[13];
  timeClient.update();
  sprintf(buffer, "%02d:%02d:%02d", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
  tft.print(buffer);
}

void disp_update(){

  //tft.fillScreen(TFT_BLACK);
  tft.setCursor(40, 120);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK, true);

  tft.setTextFont(8);  

  char buffer[13];
  //timeClient.update();
  sprintf(buffer, "%02d:%02d:%02d", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
  tft.print(buffer);
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

Serial.begin(9600);
delay(10);
displayInit();
delay(10);
disp_update();
delay(10);
SDinit();
delay(100);
loadWiFiCred();
delay(100);
wifiInit();


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
}



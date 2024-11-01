#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <NTPClient.h>


// Wi-Fi credentials
const char *ssid     = "Galaxy S23 0FEB";
const char *password = "10203040";

unsigned long lastTime;
unsigned long lastTimeSec;
int updtDisplayNTP   = 60000;
int updtDisplaySec   = 500;

#define TFT_DISPLAY_RESOLUTION_X  320
#define TFT_DISPLAY_RESOLUTION_Y  480

// TFT SPI
#define TFT_LED          33      // TFT backlight pin
#define TFT_LED_PWM      100     // dutyCycle 0-255 last minimum was 15

// NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "0.cz.pool.ntp.org", 3600, 60000); // Czech NTP server

TFT_eSPI tft = TFT_eSPI();

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
  ledcAttachPin(TFT_LED, 8);
  ledcWrite(1, TFT_LED_PWM);
  
  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
}

void wifiInit()
{
  WiFi.begin(ssid, password);
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

wifiInit();
displayInit();

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



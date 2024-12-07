**HEOS Control widget with 2.8" or 3.2" touch display on ESP32.**

Controlling HEOS is based on edited library originally by: https://github.com/janphoffmann/ESP32-Heos-Control/

I added some controls (more in the future) , fixed PID readings from devices, that were not reliable in my case.

ESP Board, that I'm using is ESPD ESP32 TFT display shield by Laskakit.cz : https://www.laskakit.cz/laskakit-espd-esp32-tft-display-shield/
 and touch display with ILI9341 display controller and XPT2046 touch controller : https://www.laskakit.cz/2-8--palcovy-barevny-dotykovy-tft-lcd-displej-240x320-ili9341-spi/

It should be possible to use 3,2" version without changing anything in firmware, they are the same.

Used libraries : TFT_eSPI, Arduino Json, NTP Client and GUI is builded on LVGL

Every settings are saved on SD Card, so SD card is necessary for now, you can use some old SD card even with very low capacity, there is only a few config files with texts.
I had a pretty low free space on ESP32 Wroom, that's why I decided to connect SD, but it can change in the future :-)

**How to build it ?**

- Clone the project to PlatformIO
- Copy lv_conf.h from lib folder and paste it to .pio\libdeps\esp32dev bewteen library folders
- Copy User_Setup.h from lib folder and paste it to .pio\libdeps\esp32dev to TFT_eSPI library folder
- for everything else should take care of platformio.ini file
- **And now hope for the best and try to build it**

![Model](https://github.com/alistaarec/Denon-HEOS-Control-ESPD/blob/main/img/SC1.png)  

![Model](https://github.com/alistaarec/Denon-HEOS-Control-ESPD/blob/main/img/SC2.png)  

![Model](https://github.com/alistaarec/Denon-HEOS-Control-ESPD/blob/main/img/SC3.png)







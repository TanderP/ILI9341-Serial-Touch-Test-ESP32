#include <Arduino.h>
#include "SPI.h"
#include "TFT_eSPI.h"
TFT_eSPI tft = TFT_eSPI();


#define LEDPIN 2
#define BL 4

void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN,OUTPUT);
  pinMode(BL,OUTPUT);

  digitalWrite(BL, HIGH);
  digitalWrite(LEDPIN, HIGH);
  tft.init();
  tft.fillScreen(TFT_ORANGE);
}

void loop() {

  uint16_t x, y;

  tft.getTouchRaw(&x, &y);
  
  Serial.printf("x: %i     ", x);

  Serial.printf("y: %i     ", y);

  Serial.printf("z: %i \n", tft.getTouchRawZ());

  delay(10);
  // put your main code here, to run repeatedly:
}

/*
#############WIRING SETUP####################

USER_SETUP_ID 42

 ILI9341_DRIVER

TFT_MISO & T_DO 19  
TFT_MOSI & T_DI 23
TFT_SCLK & T_SCK 18
TFT_CS   5  // Chip select control pin
TFT_DC    17  // Data Command control pin
TFT_RST   16 // Reset pin (could connect to RST pin)

Backlight 4

TOUCH_CS 32 // Chip select pin (T_CS) of touch screen

you can also ground the T_CS pin, but it will alwasy on
to disable it you can use 5V to T_CS Pin



*/
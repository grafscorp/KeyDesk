#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include <bitmap.hpp>

#pragma region  PINS
#define KEY_PIN1 3 //TODO
#define KEY_PIN2 4 //TODO
#define KEY_PIN3 4//TODO
#define KEY_PIN4 5//TODO
#define POTENTIOMETER_PIN 1 //TODO

#define DISPLAY_SLA_PIN A5
#define DISPLAY_SDA_PIN A4

#pragma endregion  PINS


#define DISPLAY_RESET_PIN -1
#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 128
#define BORDER_MARGIN 4
Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, DISPLAY_RESET_PIN);

bool displayStatus = false;

void PrintDisplayInfo();

void setup() {
  Serial.begin(9600);

  //BIND PINS
  // Buttons
  // pinMode(KEYPIN1, INPUT_PULLUP);
  // pinMode(KEYPIN2, INPUT_PULLUP);
  // pinMode(KEYPIN3, INPUT_PULLUP);
  // pinMode(KEYPIN4, INPUT_PULLUP);
  // // Potenntiometer
  // pinMode(POTENTIOMETERPIN, OUTPUT);

  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    //Serial.println(F("Error. SSD1306 connect failed"));
    displayStatus = false;
  }else{
    displayStatus = true;
    display.display();
    delay(200);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
  }



}             
 
void loop() {
  PrintDisplayInfo();

}

void PrintDisplayInfo()
{
  if( !displayStatus) return;
  display.clearDisplay();
  display.setCursor(0,0);
  //Draw border
  display.drawBitmap(0,0,BORDERMAP,DISPLAY_HEIGHT,DISPLAY_WIDTH,1);
  //Draw data icons
  display.drawBitmap(BORDER_MARGIN,BORDER_MARGIN,DATAMAP,DISPLAY_HEIGHT-BORDER_MARGIN*2,DISPLAY_WIDTH -BORDER_MARGIN * 2,1);
  
  //CPU DATA
  display.setCursor(30,10);
  display.print("100%");
  // display.setCursor(30,20);
  // display.print("100C");

  //RAM DATA
  display.setCursor(30,40);
  display.print("100%");
  // display.setCursor(30,47);
  // display.print("13");

  //GPU DATA
  display.setCursor(82,10);
  display.print("100%");
  // display.setCursor(82,17);
  // display.print("28");

  //TEMP DATA
  display.setCursor(82,40);
  display.print("100C");
  display.setCursor(82,50);
  display.print("100G");

  display.display();
}
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeMono24pt7b.h>
#include <Fonts/Picopixel.h>
#include <Fonts/Org_01.h>
#include "logo.h"

int sensor = 5; //phototransistor pin
int previous_state = 0;
bool finished, read_ready = false;
unsigned long time1, time2, calc;
float to_disp, to_disp_2;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  pinMode(sensor, INPUT);
  //display splash screen
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.setTextColor(WHITE);  
  display.setRotation(180);
  display.drawBitmap(0,5,logo_bits, logo_width, logo_height, WHITE);
  display.setFont(&FreeMono9pt7b);
  display.setFont(&Org_01);
  display.setCursor(15,9);  
  display.println("Laser Shutter Tester");
  display.setCursor(100,60); 
  display.setFont(&Picopixel);
  display.println("v. 2.1");
  display.display();
  delay(5000);
  display.clearDisplay();
  display.setFont(&FreeMono9pt7b);
  display.setCursor(20,32); 
  display.println("Ready...");
  display.display();
}

void loop() {
    
  int sensorState = digitalRead(sensor);
  if (previous_state == 0 && sensorState == HIGH){
    time1 = micros();
    previous_state = 1;
  }
  if (previous_state == 1 && sensorState == LOW){
    time2 = micros();
    previous_state = 0;
    read_ready = true;
  }
  if(read_ready == true){
    calc = time2-time1;
    to_disp = float(calc)/1000000;
    read_ready = false;
    finished = true;
  }
  if(finished == true){
    if(to_disp<1.0){
      to_disp_2 = 1/to_disp;
      display.clearDisplay();
      display.setFont(&FreeMono9pt7b);
      display.setCursor(15,22); 
      display.println("1");
      display.drawLine(5,32,42,32,WHITE);
      display.setCursor(8,50); 
      display.println(String(to_disp_2,0));
      display.drawLine(50,0,50,64,WHITE);
      display.setCursor(52,30); 
      display.println(String(to_disp,4));
      display.setCursor(72,50); 
      display.println("sec.");
      display.display();
    } else {
    display.clearDisplay();
    display.setFont(&FreeMono9pt7b);
    display.setCursor(35,32); 
    display.println(String(to_disp, 3));
    display.setCursor(40,50); 
    display.println("sec.");
    display.display();
    }
    finished = false;
  }
  
  delay(1);
}

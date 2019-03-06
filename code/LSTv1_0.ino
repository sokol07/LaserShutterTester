#include <Wire.h>
#include "SSD1306Wire.h"
#include "logo.h"

int sensor = 14;
int previous_state = 0;
bool finished, read_ready = false;
unsigned long time1, time2, calc;
float to_disp, to_disp_2;
SSD1306Wire display(0x3c, D2, D1);

void setup() {
  pinMode(sensor, INPUT);
  display.init();
  display.flipScreenVertically();
  display.drawXbm(0, 5, logo_width, logo_height, logo_bits);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0,0, "Laser");
  display.drawString(12,10, "Shutter");
  display.drawString(24,20, "Tester");
  display.drawString(90,50, "v. 1.0");
  display.display();
  delay(5000);
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_24);
  display.drawString(20, 20, "Ready...");
  display.display();
}

void loop() {
    
  int sensorState = digitalRead(sensor);
  if (previous_state == 0 && sensorState == HIGH){
    time1 = millis();
    previous_state = 1;
  }
  if (previous_state == 1 && sensorState == LOW){
    time2 = millis();
    previous_state = 0;
    read_ready = true;
  }
  if(read_ready == true){
    calc = time2-time1;
    to_disp = float(calc)/1000;
    read_ready = false;
    finished = true;
  }
  if(finished == true){
    if(to_disp<1.0){
      to_disp_2 = 1/to_disp;
      display.clear();
      display.setFont(ArialMT_Plain_16);
      display.drawString(20,14,"1");
      display.drawLine(5,32,42,32);
      display.setTextAlignment(TEXT_ALIGN_CENTER);
      display.drawString(25,34,String(to_disp_2,0));
      display.drawLine(50,0,50,64);
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.drawString(60,24,String(to_disp,3));
      display.drawString(110,23,"[s]");
      display.display();
    } else {
    display.clear();
    display.setFont(ArialMT_Plain_24);
    display.drawString(15, 20, String(to_disp, 3));
    display.drawString(100, 20, "s");
    display.display();
    }
    finished = false;
  }
  
  delay(1);
}

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define BUFFER_SIZE 30


U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

int beatIndex = 0;
int x_Position = 1;
float inByte = 0;
int BPM = 0;
int const_BPM = 0;
int beat_old = 0;
float beats[BUFFER_SIZE];  // Circular buffer for calculating BPM
float threshold = 620.0;  // Threshold at which BPM calculation occurs
boolean belowThreshold = true;
float height_old = 0;
float height_new = 0;

void setup() {
  // Serial.begin(9600); // Uncommnet if you want to display on serial plotter
  pinMode(4, INPUT); // LO +
  pinMode(5, INPUT); // LO -
  u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);
  u8g2.begin(); // Initialize the display
}

void draw() {
  if((digitalRead(10) == 1) || (digitalRead(11) == 1)){
    inByte = 512; 
  }
  else{
    inByte = analogRead(A0);
    if (inByte > threshold && belowThreshold == true)
    {
      calculateBPM();
      belowThreshold = false;
    }
    else if(inByte < threshold)
    {
      belowThreshold = true;
    }
    Serial.println(inByte);
  }
  inByte = map(inByte, 0, 1023, 0, 60);
  height_new = 60 - inByte;
  u8g2.drawLine(x_Position-1, height_old, x_Position, height_new);
  height_old = height_new;

  // Reset drawing when it comes to the end of the screen
  if (x_Position >= 128) {
    x_Position = 1;
    u8g2.clearBuffer(); // Clear the display buffer
  }else x_Position+=1;
}

void loop() {
  draw();
  u8g2.drawStr(5,12,"BPM:");
  if (millis() % 128 == 0) const_BPM = BPM;
  u8g2.drawStr(45,12,String(const_BPM).c_str());
  u8g2.sendBuffer();
}

void calculateBPM () 
{  
  int beat_new = millis();    // get the current time
  int diff = beat_new - beat_old;    // find the time between the last two beats
  float currentBPM = 60000 / diff;    // convert to beats per minute
  beats[beatIndex] = currentBPM; 
  float sum = 0.0;
  for (int i = 0; i < BUFFER_SIZE; i++) sum += beats[i];
  BPM = int(sum / BUFFER_SIZE);
  beat_old = beat_new;
  beatIndex = (beatIndex + 1) % 30;
}

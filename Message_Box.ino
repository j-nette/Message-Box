/* Project created by Jeanette (2022)
https://github.com/DistressedFish/Message-Box */

#include "arduino_secrets.h"
// Please edit arduino-secrets and add your own SSID and Network Password.

#include <NTPClient.h>
#include "thingProperties.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>               
#include <TimeLib.h>

int led = D0; 
int pot = A0;
int btnL = D3; //3
int btnM = D4; //2
int btnR = D6; //1

Adafruit_PCD8544 display = Adafruit_PCD8544(14, 13, 5, 15, 4); //D5, D7, D1, D8, D2
int contrast = 50; //Adafruit_PCD8544(CLK,DIN,D/C,CE,RST)

int btnMState;
int btnRState;
int btnLState;
int lightState;
int potVal;
int prevPotVal = 10;
int maxIndex = 2;
bool select = false;

long currentMillis;
int period = 500;

String menuItems[] = {
  "Light: [OFF]",
  "Messages: ",
  "Clock:"
};

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btnL, INPUT_PULLUP);
  pinMode(btnM, INPUT_PULLUP);
  pinMode(btnR, INPUT_PULLUP);
  pinMode(pot, INPUT);

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  
    /* Initialize the Display*/
  display.begin();
  display.setContrast(contrast);
  display.clearDisplay();
  display.display();
  delay(100);

  WiFi.begin(SSID, PASS);
  Serial.print("Connecting.");

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");
  timeClient.begin();
  
}

void loop() {
  ArduinoCloud.update();
  
  currentMillis = millis();
  inputUpdate();
}

void light(){
  if (lightState == 0) {
    lightState = 1;
    menuItems[0]= "Light: [ON]";
    }
  else {
    lightState = 0;
    menuItems[0]= "Light: [OFF]";
    }
  digitalWrite(led, lightState);
}

void menuUpdate(){
  if (potVal <= maxIndex){
  int n = 13;
  display.clearDisplay();
  display.setCursor(30, 1);
  display.print("MENU");
  for (int i = 0; i < maxIndex+1; i++){
    if (i == potVal) {
      Serial.print(">");
      display.setCursor(0, n);
      display.print(">");
      }
    else {
      Serial.print(" ");
      display.setCursor(0, n);
      display.print(" ");
      }
    display.print(menuItems[i]);
    Serial.println(menuItems[i]);
    prevPotVal = potVal;
    n = n + 12;
    display.display();
    } 
  }
  else{
    return;
  }
}

void onMessageChange()  {
  menuItems[2]= "Messages: [NEW]";
  menuUpdate();
}

void onCloudLedChange()  {
  light();
}

void onSelectbtnChange()  {
  if (selectbtn == HIGH){
  select = true;
  Serial.print("Selected: ");
  Serial.println(menuItems[potVal]);
  menuUpdate();
  }
  else{}
}

void inputUpdate(){
  btnMState = digitalRead(btnM);
  btnLState = digitalRead(btnL);
  btnRState = digitalRead(btnR);
  potVal = map(analogRead(pot), 1023, 0, 0, maxIndex+1); 
  
  if(potVal != prevPotVal){
    menuUpdate();
  }
  if (btnMState == LOW) {        // did it change? if so, select
    Serial.print("Selected: ");
    Serial.println(menuItems[potVal]);
    Serial.println(potVal);
    if (potVal == 0) {
      light();
      menuUpdate();
    }
    else if (potVal == 1){
      display.clearDisplay();
      display.setCursor(0,1);
      display.println("hello");
      display.setCursor(0,13);
      display.println("world :D");
      display.display();
    }
    else if (potVal == 2){
      display.clearDisplay();
      display.setCursor(0,1);
      display.print(message);
      display.display();
    }
    else{}
  }
  else if (btnLState == LOW) {        
    Serial.print("Returned to the Main Menu");
    menuUpdate();
    }
  while(millis() < currentMillis + period){}

}
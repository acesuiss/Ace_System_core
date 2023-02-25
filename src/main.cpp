#include <Arduino.h>


void setup() {
 Serial.begin(9600);
 pinMode(BUILTIN_LED,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(BUILTIN_LED,HIGH); 
  delay(500);
  digitalWrite(BUILTIN_LED,LOW);
  delay(250);
}
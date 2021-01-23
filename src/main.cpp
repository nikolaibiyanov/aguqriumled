#include  "Arduino.h"
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#define rele1 3

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
}


void loop() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    Serial.println(tm.Minute);
    if (tm.Hour >=7 && tm.Minute == 00) //включение ламп
    {
      lamp1ON();
    }
    else if (tm.Hour >=17 && tm.Minute == 00) 
    {
      lamp1OFF();
    }
  }
}
int t = 5;

void lamp1ON(){
  Serial.println("вкл лампы");
  digitalWrite(rele1, LOW);
  }
void lamp1OFF(){
  Serial.println("отключение лампы");
  digitalWrite(rele1, HIGH);
  }
  

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
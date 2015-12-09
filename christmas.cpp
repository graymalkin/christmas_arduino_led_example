#include <arduino.h>
#include <string.h>
#include "christmas.h"

void setup() {
  initialise();
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0){
    String line = Serial.readStringUntil('\n');
    if(strcmp(line.c_str(), "HO! HO! HO!") == 0){
      ho_ho_ho();
    }
    else if(strcmp(line.c_str(), "Merry Christmas!") == 0){
      merry_christmas();
    }
    else if(strcmp(line.c_str(), "Happy New Year!") == 0){
      happy_new_year();
    }
  }
  delay(1000);
  tick();
}

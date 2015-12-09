#include <arduino.h>
#include <string.h>

#define HO_HO_HO "HO! HO! HO!"
#define MERRY_CHRISTMAS "Merry Christmas!"
#define HAPPY_NEW_YEAR "Happy New Year!"

long last_tick_time = 0; 

void initialise();
void tick();

void ho_ho_ho();
void merry_christmas();
void happy_new_year();

void setup() {
  initialise();
  Serial.begin(115200);
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

  // tick();
}

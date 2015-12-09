#include <arduino.h>

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
  Serial.begin(9600);
  
}

void loop() {
  while(Serial.available() > 0){
    String line = Serial.readStringUntil('\n');
    if(line.equals("HO! HO! HO!")){
      ho_ho_ho();
    }
    else if(line.equals("Merry Christmas!")){
      merry_christmas();
    }
    else if(line.equals("Happy New Year!")){
      happy_new_year();
    }
  }
  delay(1000);
  tick();
}

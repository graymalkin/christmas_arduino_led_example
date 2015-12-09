#include "christmas.h" //Library that handles the serial input

// HO_HO_HO = "HO! HO! HO!"
// MERRY_CHRISTMAS = "Merry Christmas!"
// HAPPY_NEW_YEAR = "Happy New Year!"

bool is_red_on = false;
bool is_green_on = false;
bool is_blue_on = false;

int red_pin = 9;
int green_pin = 10;
int blue_pin = 11;

//This method is called at the beginning of the program
void initialise(){
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}

//These methods are called when HO_HO_HO, MERRY_CHRISTMASS and HAPPY_NEW_YEAR are received over serial
void ho_ho_ho(){
  is_red_on = !is_red_on;
  Serial.print(MERRY_CHRISTMAS);
}

void merry_christmas(){
  is_green_on = !is_green_on;
  Serial.print(HAPPY_NEW_YEAR);
}

void happy_new_year(){
  is_blue_on = !is_blue_on;
  Serial.print(HO_HO_HO);
}

// Turns the led at the specified pin to on or off
void update_led(int pin, bool is_on){
  if(is_on){
    digitalWrite(pin, LOW);
  }
  else {
    digitalWrite(pin, HIGH);
  }
}

// Called once every second for you to update your display
void tick(){
  update_led(red_pin, is_red_on);
  update_led(green_pin, is_green_on);
  update_led(blue_pin, is_blue_on);
}

#include <Adafruit_NeoPixel.h>

#include "christmas.h" //Library that handles the serial input
#include "TimerOne.h"

#define NEO_PIN 4
#define NEO_CNT 30

// HO_HO_HO = "HO! HO! HO!"
// MERRY_CHRISTMAS = "Merry Christmas!"
// HAPPY_NEW_YEAR = "Happy New Year!"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NEO_CNT, NEO_PIN, NEO_GRB + NEO_KHZ800);

typedef enum state_t {
  RAINBOW_CYCLE,
  RAINBOW,
  OFF
};

state_t current_state = OFF;

//This method is called at the beginning of the program
void initialise(){
  Timer1.initialize(20000);
  Timer1.attachInterrupt(tick);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

//These methods are called when HO_HO_HO, MERRY_CHRISTMASS and HAPPY_NEW_YEAR are received over serial
void ho_ho_ho(){
  current_state = RAINBOW_CYCLE;
  
  Serial.println(MERRY_CHRISTMAS);
}

void merry_christmas(){
  current_state = RAINBOW;
  
  Serial.println(HAPPY_NEW_YEAR);
}

void happy_new_year(){
  current_state = OFF;

  Serial.println(HO_HO_HO);
}

// Called once every second for you to update your display
void tick(){
  switch(current_state) {
    case RAINBOW_CYCLE:
      rainbowCycle();
      break;
    case RAINBOW:
      rainbow();
      break;
    case OFF:
    default:
      strip.show();
      break;
  }
}

uint16_t i, j;
void rainbow() {
  if(++j < 256) {
    for(i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
  }
  j &= 255;
}

// Slightly different, this makes the rainbow equally distributed throughout
uint16_t ix, jx;
void rainbowCycle() {
  if(++jx < 1203) { // 5 cycles of all colors on wheel
   for(ix = 0; ix < strip.numPixels(); ix++) {
      strip.setPixelColor(ix, Wheel(((ix * 256 / strip.numPixels()) + jx) & 255));
    }
    strip.show();
  }
  jx &= 1023;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



#include <MatrixMini.h>
#include <FastLED.h>
MatrixMini mini;

#define cmaN 100  
float cma;  // Cummulative mean average

#define DATA_PIN    2
#define NUM_LEDS    30
CRGB leds[NUM_LEDS];



void setup() {
  Serial.begin(9600);
  mini.begin();
  cma = mini.ANG1.get();
  FastLED.addLeds<WS2811,DATA_PIN,GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(100);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  int level = getSoundLevel();
  Serial.println(level);
  drawPattern(level);
  delay(1);
}


int getSoundLevel(){
  int val = mini.ANG1.get();
  cma += ((float)val - cma)/(cmaN+1);
  int level = abs(val-cma);
  level = pow(level, 1.6);
  level = constrain(level, 0, 100);
  return level;  
}

void drawPattern(int level){
  int i = NUM_LEDS-1;
  while(!leds[i] && i>0) i--;
  leds[i].fadeToBlackBy(50);
  //fadeToBlackBy( leds, NUM_LEDS, 2);
  for( int i = 0; i < NUM_LEDS*level/100; i++) {
    leds[i] = CHSV( i*90/NUM_LEDS, 255, 192);
  }
  FastLED.show();
}

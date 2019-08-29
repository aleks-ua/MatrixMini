#include <MatrixMini.h>

MatrixMini Mini;

int hue;


void setup() {
  Mini.begin();
  hue = 50;
  randomSeed(analogRead(0));
}


void loop() {
  // Set LEDs in hsv mode
  Mini.LED1.setHSV(hue, 1.0, 1.0);
  Mini.LED2.setHSV(hue);
  
  // Update hue to circle with random seed
  hue += random(1, 5);
  hue %= 360;

  delay(50);
}

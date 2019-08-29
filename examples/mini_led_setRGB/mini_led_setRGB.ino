#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();

}

void loop() {
  // set colors of leds
  Mini.LED1.setRGB(255, 0, 0);
  Mini.LED2.setRGB(0, 0, 255);

  //delay in ms
  delay(600);

  // set defferent colors
  Mini.LED1.setRGB(0, 0, 255);
  Mini.LED2.setRGB(255, 0, 0);

  //delay in ms
  delay(600);
}

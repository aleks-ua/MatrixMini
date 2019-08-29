#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
}

void loop() {
  for(int i = 0; i < 8; i++){
    Mini.LED1.set(i);
    Mini.LED2.set(i);
    delay(500);
  }
}

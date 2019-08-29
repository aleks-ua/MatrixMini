#define N 100

#include <MatrixMini.h>
MatrixMini mini;

float cma;  // Cummulative mean average

void setup() {
  Serial.begin(9600);
  mini.begin();
  cma = mini.ANG1.get();
}

void loop() {
  Serial.println(getSoundLevel());
  delay(1);
}


int getSoundLevel(){
  int val = mini.ANG1.get();
  cma += ((float)val - cma)/(N+1);
  int level = abs(val-cma);
  level = pow(level, 2);
  level = constrain(level, 0, 100);
  return level;  
}

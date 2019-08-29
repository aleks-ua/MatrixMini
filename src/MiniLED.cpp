#include "MiniLED.h"

// hue
#define PINK 315

/**************************************************************************/
/*!
    @brief  Create a RGB(led) object, un-initialized!
    You should never call this, instead have the {@link MatrixMini}
    give you a RGB object with {@link MatrixMini.getRGB}
*/
/**************************************************************************/
MiniLED::MiniLED(void){
  pwm = NULL;
  PWMR = PWMG = PWMB = 0;
}


void MiniLED::begin(
  MINI_PWMServoDriver * _pwm, 
  uint8_t r,
  uint8_t g, 
  uint8_t b)
{
  pwm = _pwm;
  PWMR = r;
  PWMG = g;
  PWMB = b;
}




/**************************************************************************/
/*!
    @brief  Control the RGB pwm frequencies
    @param  speed The 16-bit PWM value, 0 is dark, 4096 is at full density
*/
/**************************************************************************/



//
// Setting color in enum mode
//
void MiniLED::set(byte color) {
	switch(color%8){
		case 1:
			// red
			setHSV(0);
			break;
		case 2:
			// orange
			setHSV(6);
			break;
		case 3:
			// yellow
			setHSV(20);
			break;
		case 4:
			// green
			setHSV(90);
			break;
		case 5:
			// blue
			setHSV(200);
			break;
		case 6:
			// indigo
			setHSV(270);
			break;
		case 7:
			// violet
			setHSV(315);
			break;
		default:
			// black
			setRGB(0, 0, 0);			
	}
}



//
// Setting color in RGB mode
//
void MiniLED::setRGB(byte R, byte G, byte B) {
  pwm->miniSetPWM(PWMR, map(R, 0, 255, 0, 4095));
  pwm->miniSetPWM(PWMG, map(G, 0, 255, 0, 4095));
  pwm->miniSetPWM(PWMB, map(B, 0, 255, 0, 4095));
}



//
// Setting color in HSV mode
//
void MiniLED::setHSV(int H, float S, float V){
  float X, C, m, r, g, b, part;
  int c;
  r = 0; g = 0; b = 0;

  C = V*S;
  part = (float)H/60;
  X = C*(1 - fabs(fmod(part, 2) - 1));
  m = V - C;

  c = floor(part);
  switch(c){
    case 0:
      r = C;
      g = X;
      b = 0;
      break;
    case 1:
      r = X;
      g = C;
      b = 0;
      break;
    case 2:
      r = 0;
      g = C;
      b = X;
      break;
    case 3:
      r = 0;
      g = X;
      b = C;
      break;
    case 4:
      r = X;
      g = 0;
      b = C;
      break;
    case 5:
      r = C;
      g = 0;
      b = X;
      break;
  }
  r = (r+m)*255;
  g = (g+m)*255;
  b = (b+m)*255;

  setRGB(r, g, b);
}



//
// Simplified hsv
//
void MiniLED::setHSV(int H){
	setHSV(H, 1, 1);
}




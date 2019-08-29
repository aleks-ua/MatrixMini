#include "utility/MINI_PWMServoDriver.h"
#include <inttypes.h>
#include <Wire.h>


class MiniLED
{
  public:
    MiniLED(void);			
    void begin(MINI_PWMServoDriver *, uint8_t, uint8_t, uint8_t);	
	
	void set(byte);
    void setRGB(byte , byte , byte);
    void setHSV(int, float, float);
	void setHSV(int);

  private:
    uint8_t PWMR,PWMG,PWMB;
    MINI_PWMServoDriver * pwm;
};
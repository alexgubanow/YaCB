#include "fan.h"

Fan::Fan(pwmEnum pwmOutput, const PWM* pwms[])
{
	//need to check is it already taken
	pwmOut = pwms[pwmOutput];
}

Fan::~Fan()
{
}
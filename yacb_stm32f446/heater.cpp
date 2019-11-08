#include "heater.h"

Heater::Heater(pwmEnum pwmOutput, const PWM* pwms[])
{
	//need to check is it already taken
	pwmOut = pwms[pwmOutput];
}

Heater::~Heater()
{
}
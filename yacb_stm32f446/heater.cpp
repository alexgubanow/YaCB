#include "heater.h"

Heater::Heater(pwmEnum pwmOutput)
{
	//need to check is it already taken
	pwmOut = &(pwms[pwmOutput]);
}

Heater::~Heater()
{
}
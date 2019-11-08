#include "fan.h"


Fan::Fan(pwmEnum pwmOutput)
{
	//need to check is it already taken
	pwmOut = &(pwms[pwmOutput]);
}

Fan::~Fan()
{
}
#pragma once
#include "PWM.h"

class Heater
{
public:
	Heater(pwmEnum pwmOutput);
	virtual ~Heater();

private:
	PWM* pwmOut;
};
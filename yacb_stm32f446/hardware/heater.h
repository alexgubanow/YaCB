#pragma once
#include "PWM.h"

class Heater
{
public:
	Heater(pwmEnum pwmOutput, const PWM* pwms[]);
	virtual ~Heater();

private:
	const PWM* pwmOut;
};
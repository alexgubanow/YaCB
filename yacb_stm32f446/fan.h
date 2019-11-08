#pragma once
#include "PWM.h"

class Fan
{
public:
	Fan(pwmEnum pwmOutput, const PWM* pwms[]);
	virtual ~Fan();

private:
	const PWM* pwmOut;

};
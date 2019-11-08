#pragma once
#include "PWM.h"

class Fan
{
public:
	Fan(pwmEnum pwmOutput);
	virtual ~Fan();

private:
	PWM* pwmOut;

};
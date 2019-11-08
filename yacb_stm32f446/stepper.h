#pragma once
#include "PWM.h"

int drvSTP[6]
{
	pwmEnum::pwm13, pwmEnum::pwm14, pwmEnum::pwm15, pwmEnum::pwm16, pwmEnum::pwm17, pwmEnum::pwm18
};
int drvDIR[6]
{
	pwmEnum::pwm13, pwmEnum::pwm14, pwmEnum::pwm15, pwmEnum::pwm16, pwmEnum::pwm17, pwmEnum::pwm18
};
int drvEN[6]
{
	pwmEnum::pwm13, pwmEnum::pwm14, pwmEnum::pwm15, pwmEnum::pwm16, pwmEnum::pwm17, pwmEnum::pwm18
};
enum drvOutput
{
	_1, _2, _3, _4, _5, _6
};

class Stepper
{
public:
	Stepper(drvOutput drvNo, const PWM* pwms[]);
	virtual ~Stepper();

private:
	const PWM* pwmOut;

};
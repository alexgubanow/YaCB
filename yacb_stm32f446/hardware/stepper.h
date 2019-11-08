#pragma once
#include "PWM.h"
#include "pin.h"

const int drvSTP[6]
{
	pwmEnum::drvSTP1, pwmEnum::drvSTP2, pwmEnum::drvSTP3, pwmEnum::drvSTP4, pwmEnum::drvSTP5, pwmEnum::drvSTP6
};
const int drvDIR[6]
{
	pinEnum::drvDIR1, pinEnum::drvDIR2, pinEnum::drvDIR3, pinEnum::drvDIR4, pinEnum::drvDIR5, pinEnum::drvDIR6
};
const int drvEN[6]
{
	pinEnum::drvEN1, pinEnum::drvEN2, pinEnum::drvEN3, pinEnum::drvEN4, pinEnum::drvEN5, pinEnum::drvEN6
};
enum drvOutput
{
	_1, _2, _3, _4, _5, _6
};

class Stepper
{
public:
	Stepper(drvOutput drvNo, const PWM* pwms[], const pin* pins[]);
	virtual ~Stepper();

private:
	const PWM* pwmOut;
	const pin* dir;
	const pin* en;

};
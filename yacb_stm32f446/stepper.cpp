#include "stepper.h"

Stepper::Stepper(drvOutput drvNo, const PWM* pwms[], const pin* pins[])
{
	//need to check is it already taken
	pwmOut = pwms[drvSTP[drvNo]];
	dir = pins[drvDIR[drvNo]];
	en = pins[drvEN[drvNo]];
}

Stepper::~Stepper()
{
}

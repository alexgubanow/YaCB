#include "stepper.h"

Stepper::Stepper(drvOutput drvNo)
{
	//need to check is it already taken
	pwmOut = &(pwms[drvSTP[drvNo]]);
}

Stepper::~Stepper()
{
}

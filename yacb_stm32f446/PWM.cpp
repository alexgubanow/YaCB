#include "PWM.h"

PWM::PWM()
{
}

PWM::~PWM()
{
}

PWM::PWM(TIM_HandleTypeDef* _pchan)
{
	pchan = _pchan;
}

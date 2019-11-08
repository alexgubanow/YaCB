#pragma once
#include "stm32f4xx_hal_tim.h"

class PWM
{
public:
	PWM();
	~PWM();
	PWM(TIM_HandleTypeDef * _pchan);

private:
	TIM_HandleTypeDef* pchan;
};
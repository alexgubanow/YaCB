#pragma once
#include "stm32f4xx_hal_tim.h"

typedef struct pwmch
{
	TIM_HandleTypeDef* ptim;
	unsigned int ch;
};


class SysConf
{
public:
	SysConf();
	~SysConf();

private:

};
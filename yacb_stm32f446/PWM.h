#pragma once
#include "tim.h"

enum pwmEnum
{
	pwm1, pwm2, pwm3, pwm4, pwm5, pwm6, pwm7, pwm8, pwm9, pwm10, pwm11, pwm12,
	drvSTP1, drvSTP2, drvSTP3, drvSTP4, drvSTP5, drvSTP6, pwmMax
};

typedef struct 
{
	TIM_HandleTypeDef* tim;
	unsigned int ch;
}pwmch_t;

class PWM
{
public:
	PWM(pwmch_t* pwmch);
	virtual ~PWM();

private:
	pwmch_t* pwmch;
};

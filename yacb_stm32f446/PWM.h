#pragma once
#include "tim.h"

enum pwmEnum
{
	pwm1, pwm2, pwm3, pwm4, pwm5, pwm6, pwm7, pwm8, pwm9, pwm10, pwm11, pwm12, pwm13, pwm14, pwm15, pwm16, pwm17, pwm18, pwmMax
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

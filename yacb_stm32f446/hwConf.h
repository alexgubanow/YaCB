#pragma once
#include <PWM.h>

class HwConf
{
public:
	HwConf();
	~HwConf();

private:
	const PWM* pwms[pwmEnum::pwmMax] = { new PWM(new pwmch_t{&htim1, 1}), new PWM(new pwmch_t{&htim1, 1}) };

};
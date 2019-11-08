#pragma once
#include <PWM.h>
#include "pin.h"
#include <vector>
#include <heater.h>

class HwConf
{
public:
	HwConf();
	~HwConf();
	std::vector<Heater*> heaters;

private:
	const PWM* pwms[pwmEnum::pwmMax] = { new PWM(new pwmch_t{&htim1, 1}), new PWM(new pwmch_t{&htim1, 1}) };
	const pin* pins[pinEnum::pinEnumMax] = { new pin(new pinStruct_t{GPIOD, 12}), new pin(new pinStruct_t{GPIOD, 12}) };

};
#pragma once
#include <vector>
#include "hardware/PWM.h"
#include "hardware/pin.h"
#include "hardware/heater.h"

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
#include "hwConf.h"

HwConf::HwConf()
{
	heaters.push_back(new Heater(pwmEnum::pwm1, pwms));
}

HwConf::~HwConf()
{
}
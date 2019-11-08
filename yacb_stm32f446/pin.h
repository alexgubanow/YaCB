#pragma once
#include "gpio.h"


enum pinsEnum
{
	PD12, PD13, PD14, PD15, pinsEnumMax
};

typedef struct 
{
	GPIO_TypeDef* port;
	unsigned int pin;
}pinStruct_t;

class pin
{
public:
	pin(pinStruct_t* _pinStruct);
	virtual ~pin();
private:
	pinStruct_t* pinStruct;
};

pin* pins[pinsEnumMax] = { new pin(new pinStruct_t{GPIOD, 12}) };
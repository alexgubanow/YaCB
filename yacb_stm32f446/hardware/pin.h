#pragma once
#include "perif/gpio.h"


enum pinEnum
{
	PD12, PD13, PD14, PD15,
	drvDIR1, drvDIR2, drvDIR3, drvDIR4, drvDIR5, drvDIR6,
	drvEN1, drvEN2, drvEN3, drvEN4, drvEN5, drvEN6,
	pinEnumMax
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
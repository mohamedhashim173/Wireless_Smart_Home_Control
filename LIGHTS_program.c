/*
 * LIGHTS_program.c
 *
 *  Created on: Aug 9, 2023
 *      Author: MSAEED99
 */


// libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

// MCAL
#include "DIO_interface.h"

// HAL
#include "LIGHTS_config.h"
#include "LIGHTS_interface.h"


void LIGHTS_voidLightsInit(void)
{
	DIO_voidSetPinDirection(LightsPort, LightsPin, DIO_u8PIN_OUTPUT);
}

void LIGHTS_voidLightsON(void)
{
	DIO_voidSetPinValue(LightsPort, LightsPin, DIO_u8PIN_HIGH);
}

void LIGHTS_voidLightsOFF(void)
{
	DIO_voidSetPinValue(LightsPort, LightsPin, DIO_u8PIN_LOW);
}

/*
 * FAN_program.c
 *
 *  Created on: Aug 8, 2023
 *      Author: MSAEED99
 */



// libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

// MCAL
#include "DIO_interface.h"

// HAL
#include "FAN_interfance.h"
#include "FAN_config.h"


void FAN_voidFanInit(void)
{
	DIO_voidSetPinDirection(FanPort, FanPin, DIO_u8PIN_OUTPUT);
}

void FAN_voidFanON(void)
{
	DIO_voidSetPinValue(FanPort, FanPin, DIO_u8PIN_HIGH);
}

void FAN_voidFanOFF(void)
{
	DIO_voidSetPinValue(FanPort, FanPin, DIO_u8PIN_LOW);
}

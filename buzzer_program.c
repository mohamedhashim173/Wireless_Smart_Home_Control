/*
 * buzzer_program.c
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
#include "buzzer_config.h"
#include "buzzer_interface.h"


void buzzer_voidBuzzerInit(void)
{
	DIO_voidSetPinDirection(buzzerPort, buzzerPin, DIO_u8PIN_OUTPUT);
}

void buzzer_voidBuzzerON(void)
{
	DIO_voidSetPinValue(buzzerPort, buzzerPin, DIO_u8PIN_HIGH);
}


void buzzer_voidBuzzerOFF(void)
{
	DIO_voidSetPinValue(buzzerPort, buzzerPin, DIO_u8PIN_LOW);
}


void buzzer_voidInputConfirmed()
{
	buzzer_voidBuzzerON();
	_delay_ms(50);
	buzzer_voidBuzzerOFF();
}

void buzzer_voidInputRejected()
{
	buzzer_voidBuzzerON();
	_delay_ms(250);
	buzzer_voidBuzzerOFF();
	_delay_ms(50);

	buzzer_voidBuzzerON();
	_delay_ms(50);
	buzzer_voidBuzzerOFF();
	_delay_ms(50);

	buzzer_voidBuzzerON();
	_delay_ms(50);
	buzzer_voidBuzzerOFF();
}


void buzzer_voidTheifSerin(void)
{
	for(int i = 0; i < 5; i++)
	{
		buzzer_voidBuzzerON();
		_delay_ms(500);

		buzzer_voidBuzzerOFF();
		_delay_ms(500);
	}
}

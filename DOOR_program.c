/*
 * DOOR_program.c
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
#include "DOOR_config.h"
#include "DOOR_interface.h"
#include "TIMER1_interface.h"


void DOOR_voidDoorInit(void)
{
	// Set OC1A pin (PinD5) to output for PWM signal
	DIO_voidSetPinDirection(DoorPort, DoorPin, DIO_u8PIN_OUTPUT);
	// Set Periodic Time of Servo Motor (Top value = OVF value) = 20ms = 20000 counts
	TIMER1_voidSetTopVal(20000);
	// Initialize Timer1
	TIMER1_voidInit();
	// close the door
	TIMER1_voidCompareMatchVal(200);
}


void DOOR_voidDoorOpen(void)
{
	/* Set the servo motor angle by setting the value of ON Time (compare match value)
	 * ON time range = 200us:2500us (from: 0° -> 180°)
	 */
	TIMER1_voidCompareMatchVal(2500);
}


void DOOR_voidDoorClose(void)
{
	/* Set the servo motor angle by setting the value of ON Time (compare match value)
	 * ON time range = 200us:2500us (from: 0° -> 180°)
	 */
	TIMER1_voidCompareMatchVal(200);
}

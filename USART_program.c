/*
 * USART_program.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Mohamed Hashim Attiya Said
 */



// Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "USART_registers.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"



// Initialize USART communication protocol
void USART_voidInit(void)
{
	// Character Size: 8-bit
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	/* =============================
	 * UCSRC Control register value:
	 * =============================
	 * Bit 7	– URSEL  : Register Select
	 * Bit 6	– UMSEL  : USART Mode Select
	 * Bit 5:4	– UPM1:0 : Parity Mode
	 * Bit 3	– USBS   : Stop Bit Select
	 * Bit 2:1	– UCSZ1:0: Character Size
	 * Bit 0	– UCPOL  : Clock Polarity
	 */
	UCSRC = UCSRC_VAL;

	// USART Baud Rate Register: UBRRL
	UBRRL = BOAD_RATE_VAL;

	// Receiver enable
	SET_BIT(UCSRB, UCSRB_RXEN);

	// Transmitter enable
	SET_BIT(UCSRB, UCSRB_TXEN);
}

// Send data
void USART_voidSendData(u8 copy_u8Data)
{
	// Waiting to make sure that UDR data register is empty
	while(GET_BIT(UCSRA, UCSRA_UDRE) == 0);

	// Send Data to UDR
	UDR = copy_u8Data;
}


// Send data string
void USART_voidSendDataString(char* copy_u8DataString)
{
	while(*copy_u8DataString != '\0')
	{
		USART_voidSendData(*copy_u8DataString);
		copy_u8DataString++;
	}
}


// Receive data
u8 USART_u8ReceiveData(void)
{
	// Waiting to make sure that receiving is complete
	while(GET_BIT(UCSRA, UCSRA_RXC) == 0);

	// Receive data found in UDR register
	return UDR;
}



















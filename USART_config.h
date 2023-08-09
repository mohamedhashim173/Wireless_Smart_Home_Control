/*
 * USART_config.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Mohamed Hashim Attiya Said
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/* =============================
 * UCSRC Control register value:
 * =============================
 * Bit 7	– URSEL  : Register Select		, URSEL   = 1		(UCSRC Register)
 * Bit 6	– UMSEL  : USART Mode Select	, UMSEL   = 0		(Asynchronous)
 * Bit 5:4	– UPM1:0 : Parity Mode			, UPM1:0  = 00		(Disable parity)
 * Bit 3	– USBS   : Stop Bit Select		, USBS    = 0		(1-bit)
 * Bit 2:1	– UCSZ1:0: Character Size		, UCSZ1:0 = 11		(8-bit)
 * Bit 0	– UCPOL  : Clock Polarity		, UCPOL   = 0		(Don't care)
 */
#define UCSRC_VAL			0b10000110


// USART Baud Rate Register: UBRRL
#define BOAD_RATE_VAL		51



#endif /* USART_CONFIG_H_ */

/*
 * USART_registers.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Mohamed Hashim Attiya Said
 */

#ifndef USART_REGISTERS_H_
#define USART_REGISTERS_H_




// USART I/O Data Register – UDR
#define UDR					*((volatile u8*)0x2C)


/********** USART Control and Status Register A – UCSRA **********/
#define UCSRA				*((volatile u8*)0x2B)
#define UCSRA_RXC			7		// Bit 7 – RXC: USART Receive Complete
#define UCSRA_TXC			6		// Bit 6 – TXC: USART Transmit Complete
#define UCSRA_UDRE			5		// Bit 5 – UDRE: USART Data Register Empty
#define UCSRA_FE			4		// Bit 4 – FE: Frame Error
#define UCSRA_DOR			3		// Bit 3 – DOR: Data OverRun
#define UCSRA_PE			2		// Bit 2 – PE: Parity Error
#define UCSRA_U2X			1		// Bit 1 – U2X: Double the USART Transmission Speed
#define UCSRA_MPCM			0		// Bit 0 – MPCM: Multi-processor Communication Mode




/********** USART Control and Status Register B – UCSRB **********/
#define UCSRB				*((volatile u8*)0x2A)
#define UCSRB_RXCIE			7		// Bit 7 – RXCIE: RX Complete Interrupt Enable
#define UCSRB_TXCIE			6		// Bit 6 – TXCIE: TX Complete Interrupt Enable
#define UCSRB_UDRIE			5		// Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN			4		// Bit 4 – RXEN: Receiver Enable
#define UCSRB_TXEN			3		// Bit 3 – TXEN: Transmitter Enable
#define UCSRB_UCSZ2			2		// Bit 2 – UCSZ2: Character Size
#define UCSRB_RXB8			1		// Bit 1 – RXB8: Receive Data Bit 8
#define UCSRB_TXB8			0		// Bit 0 – TXB8: Transmit Data Bit 8




/********** USART Control and Status Register C – UCSRC **********/
#define UCSRC				*((volatile u8*)0x40)
// Bit 7 – URSEL: Register Select
#define UCSRC_URSEL			7
// Bit 6 – UMSEL: USART Mode Select
#define UCSRC_UMSEL			6
// Bit 5:4 – UPM1:0: Parity Mode
#define UCSRC_UPM1			5
#define UCSRC_UPM0			4
// Bit 3 – USBS: Stop Bit Select
#define UCSRC_USBS			3
// Bit 2:1 – UCSZ1:0: Character Size
#define UCSRC_UCSZ1			2
#define UCSRC_UCSZ0			1
// Bit 0 – UCPOL: Clock Polarity
#define UCSRC_UCPOL			0




/********** USART Baud Rate Registers – UBRRL and UBRRH **********/
#define UBRRH				*((volatile u8*)0x40)
#define UBRRL				*((volatile u8*)0x29)






#endif /* USART_REGISTERS_H_ */
































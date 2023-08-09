/*
 * USART_interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Mohamed Hashim Attiya Said
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_



// Initialize USART communication protocol
void USART_voidInit(void);

// Send data
void USART_voidSendData(u8 copy_u8Data);

// Send data string
void USART_voidSendDataString(char* copy_u8DataString);

// Receive data
u8 USART_u8ReceiveData(void);




#endif /* USART_INTERFACE_H_ */

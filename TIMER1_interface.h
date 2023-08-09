/*
 * TIMER1_interface.h
 *
 *  Created on: Nov 18, 2022
 *      Author: Mohamed Hashim Attiya Said
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


// Initialize Timer1
void TIMER1_voidInit(void);

// Callback function for Timer1 interrupt
void TIMER1_voidSetCallBack(void (*copy_pvUserFunc)(void));



/******************** Fast PWM Mode functions ********************/

// Set the top value (overflow value) in ICR1 register that maps to the required periodic time in Fast PWM mode
void TIMER1_voidSetTopVal(u16 copy_u16TopVal);

// Set the compare match value in OCR1A register that maps to the ON Time in Fast PWM Mode
void TIMER1_voidCompareMatchVal(u16 copy_u16CompVal);




/*************************** ICU Part ****************************/
// ICU Macros
#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE	2


// ICU Initialization
void ICU_voidInit(void);

// Select Edge, rising or falling edge
u8 ICU_u8EdgeSelect(u8 copy_u8Edge);

// Reading the signal detected by ICU
u16 ICU_u16InputCaptureRead(void);

// Enable ICU
void ICU_voidInterruptEnable(void);

// Disable ICU
void ICU_voidInterruptDisable(void);




#endif /* TIMER1_INTERFACE_H_ */

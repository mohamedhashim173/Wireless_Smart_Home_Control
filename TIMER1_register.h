/*
 * TIMER1_register.h
 *
 *  Created on: Nov 18, 2022
 *      Author: Mohamed Hashim Attiya Said
 */

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

/*** Timer/Counter1 Control Register A – TCCR1A ***/
#define TCCR1A			*((volatile u8*)0x4F)
// Compare Output Mode for Channel A
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
// Compare Output Mode for Channel B
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1B0	4
// Force Output Compare for Channel A
#define TCCR1A_FOC1A	3
// Force Output Compare for Channel B
#define TCCR1A_FOC1B	2
// Waveform Generation Mode
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10	0


/*** Timer/Counter1 Control Register B – TCCR1B ***/
#define TCCR1B			*((volatile u8*)0x4E)
// Input Capture Noise Canceler
#define TCCR1B_ICNC1	7
// Input Capture Edge Select
#define TCCR1B_ICES1	6
// Waveform Generation Mode
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3
// Clock Select (Pre-scaler)
#define TCCR1B_CS12		2
#define TCCR1B_CS11		1
#define TCCR1B_CS10		0


/*** Timer/Counter Interrupt Mask Register – TIMSK ***/
#define TIMSK			*((volatile u8*)0x59)
// Timer/Counter1, Input Capture Interrupt Enable
#define TIMSK_TICIE1	5
// Timer/Counter1, Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1A	4
// Timer/Counter1, Output Compare B Match Interrupt Enable
#define TIMSK_OCIE1B	3
// Timer/Counter1, Overflow Interrupt Enable
#define TIMSK_TOIE1		2

/*** Timer/Counter1 – TCNT1H and TCNT1L ***/
#define TCNT1			*((volatile u16*)0x4C)

/*** Output Compare Register 1 A – OCR1AH and OCR1AL ***/
#define OCR1A			*((volatile u16*)0x4A)

/*** Output Compare Register 1 B – OCR1BH and OCR1BL ***/
#define OCR1B			*((volatile u16*)0x48)

/*** Input Capture Register 1 – ICR1H and ICR1L ***/
#define ICR1			*((volatile u16*)0x46)




#endif /* TIMER1_REGISTER_H_ */

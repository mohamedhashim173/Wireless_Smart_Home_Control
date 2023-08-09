/*
 * LCD_interface.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohamed Hashim Attiya Said
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


// initiate LCD (must be called before using LCD functions)
void LCD_voidInit(void);

// send command to LCD
void LCD_voidSendCommand(u8 copy_u8Command);

// print character On LCD
void LCD_voidSendCharacter(u8 copy_u8Character);

// Send string to LCD (input argument is a pointer to the beginning of the string
void LCD_voidSendString(char* copy_pcString);

// Control the position of the printed characters
void LCD_voidPositionSet(u8 copy_u8RowNum, u8 copy_u8ColNum);

// Draw special character
void LCD_voidDrawSpecialCharacter(u8* copy_pu8Pattern, u8 copy_u8LocationNum, u8 copy_u8RowNum, u8 copy_u8ColNum);

// Clear display
void LCD_voidClearScreen(void);

#endif /* LCD_INTERFACE_H_ */

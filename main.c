/*
 * main.c
 *
 *  Created on: Jan 14, 2023
 *      Author: Mohamed Hashim Attiya Said
 */

// Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <stdbool.h>

// MCAL
#include "DIO_interface.h"
#include "USART_interface.h"
#include "TIMER1_interface.h"

// HAL
#include "LCD_interface.h"
#include "buzzer_interface.h"
#include "LIGHTS_interface.h"
#include "FAN_interfance.h"
#include "DOOR_interface.h"

// Prototypes
bool validInput(u8 local_u8Input);
void LCDfeedback_voidWrongUsername(void);
void LCDfeedback_voidWrongPassword(void);


// Send data from mobile device using HC-05 Bluetooth Terminal App. Then, make the action on MCU
/* ===================================================
 * UART communication protocol with Bluetooth Module:
 * ===================================================
 * Setting UART communication between ATmega32 and HC-05 Bluetooth Module
 * Application:
 * 	1- Login authentication. If invalid, theif serin executes.
 * 	2- Make actions on smart home: LED ON, LED OFF, Door opened, and Door closed.
 */

void main(void)
{
	u8 local_u8Data = 0;
	bool userName = false;
	bool password = false;
	bool login_status = false;

	// credintials database (username, password)
	u8 credintials[10][2] =
	{
			{'A', 'a'},
			{'B', 'b'},
			{'C', 'c'},
			{'D', 'd'},
			{'E', 'e'},
			{'F', 'f'},
			{'G', 'g'},
			{'H', 'h'},
			{'I', 'i'},
			{'J', 'j'}
	};


	/******************************** Intialize Perpherals ********************************/
	// Initialize Lights pin as output
	LIGHTS_voidLightsInit();

	// Initialize Fan pin as output
	FAN_voidFanInit();

	// Set Buzzer pin as output
	buzzer_voidBuzzerInit();

	// Initialize LCD
	LCD_voidInit();

	// Initialize Timer1: Set OC1A pin (PinD5) to output for PWM signal for doot control
	DOOR_voidDoorInit();


	/******************************** UART Preferences ********************************/
	/* =======================================
	 * Initialize the direction of USART pins:
	 * =======================================
	 * RX (PinD0) as input	: connect to TX in Bluetooth Module.
	 * TX (PinD1) as output	: connect to RX in Bluetooth Module.
	 */
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);

	// Initialize USART communication
	USART_voidInit();



	/********************************** Application ***********************************/

	while(1)
	{

		// UART login message
		USART_voidSendDataString("User Name = ");

		// login screen
		LCD_voidSendString("User Name:");
		LCD_voidPositionSet(1, 0);
		LCD_voidSendString("Password :");


		/********************************** Username **********************************/
		u8 i;
		while(!userName)
		{
			// set curser to enter username
			LCD_voidPositionSet(0, 11);

			// Receive the data from Bluetooth Module
			local_u8Data = USART_u8ReceiveData();
			bool local_u8Data_val = validInput(local_u8Data);

			// check valid AT command
			if(!local_u8Data_val)
			{
				continue;
			}

			// check username
			for(i = 0; i < 10; i++)
			{
				if(local_u8Data == credintials[i][0])
				{
					userName = true;

					// Buzzer feedback
					buzzer_voidInputConfirmed();

					// Mobile feedback
					USART_voidSendData(credintials[i][0]);
					USART_voidSendData(10);			// Print new line
					USART_voidSendDataString("Password = ");

					// LCD feedback
					LCD_voidSendString("***");
					LCD_voidPositionSet(1, 11);		// set curser to enter password

					break;
				}
			}

			// username not found
			if (!userName)
			{

				// buzzer feedback
				buzzer_voidInputRejected();

				// Mobile feedback
				USART_voidSendData(local_u8Data);
				USART_voidSendDataString("                    ");	// white space
				USART_voidSendDataString("(Invalid username)");
				USART_voidSendData(10);		// Print new line
				USART_voidSendDataString("User Name = ");

				// LCD feedback
				LCDfeedback_voidWrongUsername();
			}
		}


		/********************************** Password **********************************/

		while(!password)
		{
			// set curser for username
			LCD_voidPositionSet(1, 11);

			// Receive the data from Bluetooth Module
			local_u8Data = USART_u8ReceiveData();
			bool local_u8Data_val = validInput(local_u8Data);

			// check valid AT command
			if(!local_u8Data_val)
			{
				continue;
			}

			// search for password
			for(u8 j = 0; j < 10; j++)
			{
				if(local_u8Data == credintials[i][1])
				{
					password = true;

					// Buzzer feedback
					buzzer_voidInputConfirmed();

					// UART feedback
					USART_voidSendData(credintials[i][1]);
					USART_voidSendData(10);		// Print new line

					// LCD feedback
					LCD_voidSendString("***");

					break;
				}
			}

			// incorrect password
			if (!password)
			{

				// buzzer feedback
				buzzer_voidInputRejected();

				// UART feedback
				USART_voidSendData(local_u8Data);
				USART_voidSendDataString("                    ");	// white space
				USART_voidSendDataString("(Invalid password)");
				USART_voidSendData(10);		// Print new line
				USART_voidSendDataString("Password = ");

				// LCD feedback
				LCDfeedback_voidWrongPassword();
			}
		}


		/********************************** Check Login **********************************/

		if(userName && password)
		{
			login_status = true;

			// UART feedback
			USART_voidSendData(10);		// Print new line
			USART_voidSendDataString("==============================");
			USART_voidSendData(10);		// Print new line
			USART_voidSendDataString("WELCOME Home!");
			USART_voidSendData(10);		// Print new line

			// LCD feedback
			LCD_voidClearScreen();
			LCD_voidSendString("Welcome Home!");
			LCD_voidPositionSet(0, 20); // hide curser
		}


		/************************************ Logged in ************************************/

		while(login_status)
		{
			// Receive the data from Bluetooth Module
			local_u8Data = USART_u8ReceiveData();
			bool local_u8Data_val = validInput(local_u8Data);

			// check valid AT command
			if(!local_u8Data_val)
			{
				continue;
			}

			// Logout
			if(local_u8Data == '0')
			{

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// reset login data
				userName = false;
				password = false;
				login_status = false;

				// send data to UART device
				USART_voidSendData(10);		// Print new line
				USART_voidSendDataString("Logged out");
				USART_voidSendData(10);		// Print new line
				USART_voidSendDataString("==============================");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidClearScreen();
				LCD_voidSendString("** Logged out **");
				_delay_ms(2000);
				LCD_voidPositionSet(0, 20);
				LCD_voidClearScreen();
			}

			// Lights ON
			else if(local_u8Data == '1')
			{
				LIGHTS_voidLightsON();

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// send data to UART device
				USART_voidSendDataString("Lights ON");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Lights ON       ");
				LCD_voidPositionSet(0, 20); // hide curser
			}

			// Lights OFF
			else if(local_u8Data == '2')
			{
				LIGHTS_voidLightsOFF();

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// send data to UART device
				USART_voidSendDataString("Lights OFF");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Lights OFF      ");
				LCD_voidPositionSet(0, 20); // hide curser
			}

			// Fan ON
			else if(local_u8Data == '3')
			{
				FAN_voidFanON();

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// send data to UART device
				USART_voidSendDataString("Fan ON");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Fan ON          ");
				LCD_voidPositionSet(0, 20); // hide curser
			}

			// Fan OFF
			else if(local_u8Data == '4')
			{
				FAN_voidFanOFF();

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// send data to UART device
				USART_voidSendDataString("Fan OFF");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Fan OFF         ");
				LCD_voidPositionSet(0, 20); // hide curser
			}

			// Door Open
			else if(local_u8Data == '5')
			{
				DOOR_voidDoorOpen();

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// send data to UART device
				USART_voidSendDataString("Door Open");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Door Open       ");
				LCD_voidPositionSet(0, 20); // hide curser

			}

			// Door Close
			else if(local_u8Data == '6')
			{
				DOOR_voidDoorClose();

				// buzzer feedback
				buzzer_voidInputConfirmed();

				// send data to UART device
				USART_voidSendDataString("Door Close");
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Door Close      ");
				LCD_voidPositionSet(0, 20); // hide curser
			}

			// Invalid option
			else
			{
				// buzzer feedback
				buzzer_voidInputRejected();

				// send data to UART device
				USART_voidSendDataString("Invalid option: ");
				USART_voidSendData(local_u8Data);
				USART_voidSendData(10);		// Print new line

				// send data to LCD
				LCD_voidPositionSet(1, 0);
				LCD_voidSendString("Invalid Option  ");
				LCD_voidPositionSet(0, 20);
			}
		}
	}
}


bool validInput(u8 local_u8Input)
{
	return ((local_u8Input >= '0') && (local_u8Input <= '9')) || ((local_u8Input >= 'a') && (local_u8Input <= 'z')) || ((local_u8Input >= 'A') && (local_u8Input <= 'Z'));
}

void LCDfeedback_voidWrongUsername(void)
{
	LCD_voidPositionSet(0, 11);
	LCD_voidSendString("***  ");
	_delay_ms(100);

	LCD_voidPositionSet(0, 11);
	LCD_voidSendString(" *** ");
	_delay_ms(100);

	LCD_voidPositionSet(0, 11);
	LCD_voidSendString("***  ");
	_delay_ms(100);

	LCD_voidPositionSet(0, 11);
	LCD_voidSendString(" *** ");
	_delay_ms(100);

	LCD_voidPositionSet(0, 11);
	LCD_voidSendString("***  ");
	_delay_ms(100);

	LCD_voidPositionSet(0, 11);
	LCD_voidSendString("     ");
	LCD_voidPositionSet(0, 11);
}

void LCDfeedback_voidWrongPassword(void)
{
	LCD_voidPositionSet(1, 11);
	LCD_voidSendString("***  ");
	_delay_ms(100);

	LCD_voidPositionSet(1, 11);
	LCD_voidSendString(" *** ");
	_delay_ms(100);

	LCD_voidPositionSet(1, 11);
	LCD_voidSendString("***  ");
	_delay_ms(100);

	LCD_voidPositionSet(1, 11);
	LCD_voidSendString(" *** ");
	_delay_ms(100);

	LCD_voidPositionSet(1, 11);
	LCD_voidSendString("***  ");
	_delay_ms(100);

	LCD_voidPositionSet(1, 11);
	LCD_voidSendString("     ");
	LCD_voidPositionSet(1, 11);
}



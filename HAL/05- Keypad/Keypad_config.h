/*
 * Keypad_config.h
 *
 *  Created on: Feb 12, 2021
 *      Author: Kishk
 */

#ifndef HAL_05__KEYPAD_KEYPAD_CONFIG_H_
#define HAL_05__KEYPAD_KEYPAD_CONFIG_H_


#define Keypad_u8_R0		DIO_PORTC_PIN7
#define Keypad_u8_R1		DIO_PORTC_PIN6
#define Keypad_u8_R2		DIO_PORTC_PIN5
#define Keypad_u8_R3		DIO_PORTC_PIN4

#define Keypad_u8_C0		DIO_PORTC_PIN3
#define Keypad_u8_C1		DIO_PORTC_PIN2
#define Keypad_u8_C2		DIO_PORTC_PIN1
#define Keypad_u8_C3		DIO_PORTC_PIN0


/* OPTIONS FOR PULLUP FOR KEYPADE
 * ENABLE
 * DISABLE
 */

#define Keypad_u8_Internal_PULLUP	Keypad_u8_ENABLE_PULLUP

#define Keypad_u8_Switch_0                        '1'
#define Keypad_u8_Switch_1                        '2'
#define Keypad_u8_Switch_2                        '3'
#define Keypad_u8_Switch_3                        '+'
#define Keypad_u8_Switch_4                        '4'
#define Keypad_u8_Switch_5                        '5'
#define Keypad_u8_Switch_6                        '6'
#define Keypad_u8_Switch_7                        '-'
#define Keypad_u8_Switch_8                        '7'
#define Keypad_u8_Switch_9                        '8'
#define Keypad_u8_Switch_10                       '9'
#define Keypad_u8_Switch_11                       '*'
#define Keypad_u8_Switch_12                       'E'
#define Keypad_u8_Switch_13                       '0'
#define Keypad_u8_Switch_14                       'C'
#define Keypad_u8_Switch_15                       '/'

u8 Keypad_u8Buttons[Keypad_u8_ROWS][Keypad_u8_COLS] = {		{Keypad_u8_Switch_0,  Keypad_u8_Switch_1,  Keypad_u8_Switch_2,  Keypad_u8_Switch_3},
															{Keypad_u8_Switch_4,  Keypad_u8_Switch_5,  Keypad_u8_Switch_6,  Keypad_u8_Switch_7},
															{Keypad_u8_Switch_8,  Keypad_u8_Switch_9,  Keypad_u8_Switch_10, Keypad_u8_Switch_11,},
															{Keypad_u8_Switch_12, Keypad_u8_Switch_13, Keypad_u8_Switch_14, Keypad_u8_Switch_15}	};


#endif /* HAL_05__KEYPAD_KEYPAD_CONFIG_H_ */

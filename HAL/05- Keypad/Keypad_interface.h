/*
 * Keypad_interface.h
 *
 *  Created on: Feb 12, 2021
 *      Author: Kishk
 */

#ifndef HAL_05__KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_05__KEYPAD_KEYPAD_INTERFACE_H_

#define Keypad_u8_ROWS	4
#define Keypad_u8_COLS	4

#define Keypad_u8_ENABLE_PULLUP 	1
#define Keypad_u8_DISABLE_PULLUP 	1

void Keypad_voidInit(void);

u8 Keypad_u8GetPressed(void);

#endif /* HAL_05__KEYPAD_KEYPAD_INTERFACE_H_ */

/*
 * Keypad_program.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Kishk
 */

#include <util/delay.h>
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "../../MCAL/01-DIO/DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_config.h"
#include "Keypad_private.h"


void Keypad_voidInit(void){
	DIO_enumSetPinDirection(Keypad_u8_R0,DIO_INPUT);
	DIO_enumSetPinDirection(Keypad_u8_R1,DIO_INPUT);
	DIO_enumSetPinDirection(Keypad_u8_R2,DIO_INPUT);
	DIO_enumSetPinDirection(Keypad_u8_R3,DIO_INPUT);

#if Keypad_u8_Internal_PULLUP == Keypad_u8_ENABLE_PULLUP
	DIO_voidActivePullUp(Keypad_u8_R0);
	DIO_voidActivePullUp(Keypad_u8_R1);
	DIO_voidActivePullUp(Keypad_u8_R2);
	DIO_voidActivePullUp(Keypad_u8_R3);
#endif
	DIO_enumSetPinDirection(Keypad_u8_C0,DIO_OUTPUT);
	DIO_enumSetPinDirection(Keypad_u8_C1,DIO_OUTPUT);
	DIO_enumSetPinDirection(Keypad_u8_C2,DIO_OUTPUT);
	DIO_enumSetPinDirection(Keypad_u8_C3,DIO_OUTPUT);

	DIO_enumSetPinValue(Keypad_u8_C0,DIO_HIGH);
	DIO_enumSetPinValue(Keypad_u8_C1,DIO_HIGH);
	DIO_enumSetPinValue(Keypad_u8_C2,DIO_HIGH);
	DIO_enumSetPinValue(Keypad_u8_C3,DIO_HIGH);
}


u8 Keypad_u8GetPressed(void){
	u8 LOC_u8ColIterator = 0;
	u8 LOC_u8RowIterator = 0;
	u8 LOC_u8ReturnData  = 0;
	for(LOC_u8ColIterator = 0 ; LOC_u8ColIterator < 4 ; LOC_u8ColIterator++){
		DIO_enumSetPinValue(Keypad_arrColPins[LOC_u8ColIterator],DIO_LOW);
		for(LOC_u8RowIterator = 0 ; LOC_u8RowIterator < 4 ; LOC_u8RowIterator++){
			if(DIO_u8ReadPinValue(Keypad_arrRowPins[LOC_u8RowIterator])== DIO_LOW){
				_delay_ms(50);
				if(DIO_u8ReadPinValue(Keypad_arrRowPins[LOC_u8RowIterator])== DIO_LOW){
					LOC_u8ReturnData = Keypad_u8Buttons[ LOC_u8RowIterator  ][ LOC_u8ColIterator  ];
				}
				while(DIO_u8ReadPinValue(Keypad_arrRowPins[LOC_u8RowIterator]) == DIO_LOW){

				}
				break;
			}

		}
		DIO_enumSetPinValue(Keypad_arrColPins[LOC_u8ColIterator],DIO_HIGH);
	}
	return LOC_u8ReturnData;
}

/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../HAL/04- CLCD/CLCD_interface.h"
#include "../HAL/05- Keypad/Keypad_interface.h"



u8 toInt(u8 Copy_u8Ch);
void clearArray(u8 *Copy_ptrArray);

int main(void) {
	CLCD_voidInit();
	Keypad_voidInit();
	u8 LOC_u8Iterator = 0;
	u8 LOC_u8Counter = 0;
	u8 LOC_u8ComeData = 0;
	u8 LOC_u8ArrOperations[10] 	  		   = { 0 };
	u8 LOC_u8ArrOperands[10] 	   		   = { 0 };
	u8 LOC_u8ArrOperandsLength[10] 		   = { 0 };
	u8 LOC_u8OperationCounter = 0;
	u8 LOC_u8OperationFlag	=	0;
	u8 LOC_u8DivideByZeroFlag	= 0 ;
	s32 LOC_s32Result 		=	0;
	CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
	CLCD_voidSendString((u8 *) "Calculator V0.0!");
	_delay_ms(2000);
	CLCD_voidClearDisplay();
	while (1) {
		LOC_u8ComeData = Keypad_u8GetPressed();
		if (LOC_u8ComeData != 0) {
			switch(LOC_u8ComeData){
			case 'E':
				if(LOC_u8OperationCounter > 0){
					LOC_s32Result = LOC_u8ArrOperands[LOC_u8Iterator];
					for(LOC_u8Iterator = 0 ;  LOC_u8Iterator < LOC_u8OperationCounter ; LOC_u8Iterator++ ){
						/*Check Operation and Print The Result */
						if(LOC_u8DivideByZeroFlag){break;}
						switch(LOC_u8ArrOperations[LOC_u8Iterator]){
						case '+':
							LOC_s32Result += LOC_u8ArrOperands[LOC_u8Iterator + 1];
							break;
						case '-':
							LOC_s32Result -= LOC_u8ArrOperands[LOC_u8Iterator + 1];
							break;

						case '*':
							LOC_s32Result *= LOC_u8ArrOperands[LOC_u8Iterator + 1];
							break;

						case '/':
							if(LOC_u8ArrOperands[LOC_u8Iterator + 1] != 0){ LOC_s32Result /= LOC_u8ArrOperands[LOC_u8Iterator + 1]; }
							else {	CLCD_voidClearDisplay(); CLCD_voidSendString((u8 *) "Divide By ZERO"); LOC_u8DivideByZeroFlag = 1;}
							break;
						}

					}
					if(!LOC_u8DivideByZeroFlag){
						CLCD_voidSetPosition(CLCD_ROW_2 ,CLCD_COL_1);
						if(LOC_s32Result >= 0 ){CLCD_voidSendNumber(LOC_s32Result);}
						else{CLCD_voidSendData('-'); CLCD_voidSendNumber(LOC_s32Result * -1 );}
					}
				}
				break;

			case 'C':
				CLCD_voidClearDisplay();
				LOC_u8Iterator = 0;
				LOC_u8Counter = 0;
				LOC_u8ComeData = 0;
				clearArray(LOC_u8ArrOperations);
				clearArray(LOC_u8ArrOperands);
				clearArray(LOC_u8ArrOperandsLength);
				LOC_u8OperationCounter = 0;
				LOC_u8OperationFlag	=	0;
				LOC_u8DivideByZeroFlag	= 0;
				LOC_s32Result 		=	0;
				break;

			case '+':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '+' ;
				LOC_u8OperationCounter++;
				LOC_u8Counter++;
				LOC_u8OperationFlag = 1;
				CLCD_voidSendData('+');
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '+' ;
					CLCD_voidSetPosition(CLCD_ROW_1 , LOC_u8Counter);
					CLCD_voidSendData('+');

				}
				break;

			case '-':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '-' ;
				LOC_u8OperationCounter++;
				LOC_u8OperationFlag = 1;
				LOC_u8Counter++;
				CLCD_voidSendData('-');
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '-' ;
					CLCD_voidSetPosition(CLCD_ROW_1 , LOC_u8Counter);
					CLCD_voidSendData('-');
				}
				break;

			case '*':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '*' ;
				LOC_u8OperationCounter++;
				LOC_u8OperationFlag = 1;
				LOC_u8Counter++;
				CLCD_voidSendData('*');

				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '*' ;
					CLCD_voidSetPosition(CLCD_ROW_1 , LOC_u8Counter);
					CLCD_voidSendData('*');
				}
				break;

			case '/':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '/' ;
				LOC_u8OperationCounter++;
				LOC_u8OperationFlag = 1;
				LOC_u8Counter++;
				CLCD_voidSendData('/');
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '/' ;
					CLCD_voidSetPosition(CLCD_ROW_1 , LOC_u8Counter);
					CLCD_voidSendData('/');
				}
				break;

			default:
				LOC_u8OperationFlag = 0;
				LOC_u8Counter++;
				CLCD_voidSendData(LOC_u8ComeData);
				if(LOC_u8ArrOperandsLength[LOC_u8OperationCounter] == 0){
					LOC_u8ArrOperands[LOC_u8OperationCounter] = toInt(LOC_u8ComeData);
					LOC_u8ArrOperandsLength[LOC_u8OperationCounter]++;
				}
				else{
					LOC_u8ArrOperands[LOC_u8OperationCounter] = LOC_u8ArrOperands[LOC_u8OperationCounter] * 10 +  toInt(LOC_u8ComeData);
					LOC_u8ArrOperandsLength[LOC_u8OperationCounter]++;
				}
				break;

			}
		}
	}
	return 0;

}


u8 toInt(u8 Copy_u8Ch){
	return Copy_u8Ch - '0';
}


void clearArray(u8 *Copy_ptrArray){
	for(u8 LOC_u8Iterator = 0 ; LOC_u8Iterator < 10 ; LOC_u8Iterator++){
		Copy_ptrArray[LOC_u8Iterator] = 0;
	}
}

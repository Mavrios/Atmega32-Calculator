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

int main(void) {
	CLCD_voidInit();
	Keypad_voidInit();
	u8 LOC_u8Iterator = 0;
	u8 LOC_u8Counter = 0;
	u8 LOC_u8ComeData = 0;
	u8 LOC_u8ArrOperations[10] 	   = { 0 };
	u8 LOC_u8ArrOperands[10] 	   = { 0 };
	u8 LOC_u8ArrOperandsLength[10] = { 0 };
	u8 LOC_u8OperationCounter = 0;
	u8 LOC_u8OperationFlag	=	0;

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
					for(LOC_u8Iterator = 0 ;  LOC_u8Iterator <LOC_u8OperationCounter ; LOC_u8Iterator++ ){
						/*Check Operation and Print The Result */
					}
				}
				break;

			case '+':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '+' ;
				LOC_u8OperationCounter++;
				LOC_u8Counter++;
				LOC_u8OperationFlag = 1;
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '+' ;
				}
				break;

			case '-':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '-' ;
				LOC_u8OperationCounter++;
				LOC_u8OperationFlag = 1;
				LOC_u8Counter++;
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '-' ;
				}
				break;

			case '*':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '*' ;
				LOC_u8OperationCounter++;
				LOC_u8OperationFlag = 1;
				LOC_u8Counter++;
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '*' ;
				}
				break;

			case '/':
				if(LOC_u8OperationFlag != 1){
				LOC_u8ArrOperations[LOC_u8OperationCounter] = '/' ;
				LOC_u8OperationCounter++;
				LOC_u8OperationFlag = 1;
				LOC_u8Counter++;
				}
				else{
					LOC_u8ArrOperations[LOC_u8OperationCounter - 1] = '/' ;
				}
				break;

			default:
				LOC_u8Counter++;
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


/*			if (LOC_u8ComeData == 'E') {
				Calculator_u32OperationResult(LOC_u8ArrEntered);
			}
			else if(LOC_u8ComeData == 'C'){
				 CLEAR LCD AND CLEAR ARRAY
			}
			else {
				if (LOC_u8ComeData == '+' || LOC_u8ComeData == '-'
						|| LOC_u8ComeData == '*' || LOC_u8ComeData == '/') {
					if (LOC_u8Flag == 1) {
						CLCD_voidSetPosition(CLCD_ROW_1, LOC_u8Counter);
						CLCD_voidSendData(LOC_u8ComeData);
						LOC_u8ArrEntered[LOC_u8Counter - 1] = LOC_u8ComeData;
					} else {
						LOC_u8ArrEntered[LOC_u8Counter] = LOC_u8ComeData;
						CLCD_voidSendData(LOC_u8ComeData);
						LOC_u8Counter++;
						LOC_u8Flag = 0;
						LOC_u8Flag++;
					}

				} else {
					LOC_u8ArrEntered[LOC_u8Counter] = LOC_u8ComeData;
					CLCD_voidSendData(LOC_u8ComeData);
					LOC_u8Counter++;
					LOC_u8Flag = 0;
				}
			}*/
		}
	}
	return 0;

}


u8 toInt(u8 Copy_u8Ch){
	return Copy_u8Ch - '0';
}


/*
u32 Calculator_u32OperationResult(u8 * Copy_u8PtrEntered){
	u16 LOC_u16ArrOperand[10];
	u8  LOC_u8ArrOperation[10];
	u8  LOC_u8OperationCounter = 0;
	u8  LOC_u8OperandCounter = 0;
	u8  LOC_u8OperandCounter2 = 0;
	u8  LOC_u8Iterator  = 0 ;
	u8 	LOC_u8Iterator2 = 0 ;
	u8  LOC_u8Iterator3 = 0 ;
	f32 LOC_f32Result = 0;
	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < 20 ; LOC_u8Iterator++){
		if(Copy_u8PtrEntered[LOC_u8Iterator]  == '+' || Copy_u8PtrEntered[LOC_u8Iterator]  == '-'|| Copy_u8PtrEntered[LOC_u8Iterator]  == '*' || Copy_u8PtrEntered[LOC_u8Iterator]  == '/'){
			for(LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < LOC_u8OperandCounter ; LOC_u8Iterator2++){
				for(LOC_u8Iterator3 = 0 ; LOC_u8Iterator3 < LOC_u8OperandCounter - 1; LOC_u8Iterator3++ ){
				LOC_u16ArrOperand[LOC_u8OperandCounter2] += (Copy_u8PtrEntered[LOC_u8Iterator - LOC_u8OperandCounter] - 48) * 10;
				}
			}
			LOC_u8OperandCounter2++;
			LOC_u8OperandCounter = 0;
			LOC_u8ArrOperation[LOC_u8OperationCounter++] = Copy_u8PtrEntered[LOC_u8Iterator];
		}
		else{
			LOC_u8OperandCounter++;
		}
	}


	LOC_f32Result = LOC_u16ArrOperand[0];
	 DO EQUATION
	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < LOC_u8OperandCounter2 - 1 ; LOC_u8Iterator++){
		switch (LOC_u8ArrOperation[LOC_u8Iterator]){
		case '+':
			LOC_f32Result += LOC_u16ArrOperand[LOC_u8Iterator + 1];
			break;
		case '-':
			LOC_f32Result -= LOC_u16ArrOperand[LOC_u8Iterator + 1];
			break;
		case '*':
			LOC_f32Result *= LOC_u16ArrOperand[LOC_u8Iterator + 1];
			break;
		case '/':
			if(LOC_u16ArrOperand[LOC_u8Iterator + 1] == 0){CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_1); CLCD_voidSendString((u8 *) "Divide By ZERO "); return 0; }
			else{LOC_f32Result /= LOC_u16ArrOperand[LOC_u8Iterator + 1];}
			break;
		}
	}

	if(LOC_f32Result < 0){LOC_f32Result *= -1 ; CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_1); CLCD_voidSendData('-'); CLCD_voidSendNumber(LOC_f32Result);}
	else{CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_1); CLCD_voidSendNumber(LOC_f32Result);}
	return 1;
}

*/


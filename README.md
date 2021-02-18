# Atmega32 Calculator
* This Project is implemented with:- 
- Atmega32 Microcontroller
- LCD 16x2
- KEYPAD 4x4

## Architecture Layer Applied
- APP Folder has the Main Application --> main.c
- HAL Folder has CLCD Driver and KEYPAD Driver (Just Include Interface.h in ur main program)
- MCAL Folder has DIO Driver (which is needed because HAL Layer Connecting to MCAL Layer).
- Services Folder has .h Files has useful Macros to make the code easier and more readable.

## Calculator Feature:- 
- This Calculator can handle up to 7 Operation.
- Available Operations (+ , - , * , /).
- There's Button for Clearing.
- There's Button 'E' To Enter Equation and Display The answer.

## Configrations:-
###### KEYPAD Driver Configration:-
* Go to this Directory (HAL -> 05- KEYPAD -> Keypad.config.h)
- Edit Keypad Pins

###### LCD Driver Configration:-
* Go to this Directory (HAL -> 04- CLCD -> CLCD.config.h)
- Edit LCD PINS


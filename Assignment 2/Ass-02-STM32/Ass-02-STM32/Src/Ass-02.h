//     $Date: 2017-04-04 04:00:13 +1000 (Tue, 04 Apr 2017) $
// $Revision: 872 $
//   $Author: Peter $

// Assignment 2 include file

#ifndef ASS_02_H_
#define ASS_02_H_

// Standard includes
#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#include "openx07v_c_lcd.h"
#include "touch_panel.h"
#else
#include <windows.h>
#endif
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//Data Types
//**************Global Variables*******************************//
#define MAXBUFF 101 //Maximum size of buffer strings
volatile extern uint8_t Debug;


//For question 1
typedef struct{
	int8_t *NameString;
	int8_t (*Function_p)(uint8_t ArgNum, uint8_t *ArgStrings[]);
	int8_t *HelpString;
}command_s;

//********************For question 2****************************//
typedef struct{
	uint8_t *Character_String;
	uint16_t Loc[4];
	uint8_t *Font;
	uint32_t BackColour;
	uint32_t ToggleColour;
	uint32_t TextColour;
	Line_ModeTypdef MODE;
	int8_t OffSet[2];
	float (*Opperation_p)(uint8_t* arg1, uint8_t* arg2);
}button_s;


// Assignment main
extern void Ass_02_Main(void);

//
// REPLACE THE EXAMPLE CODE WITH YOUR CODE
//

// Question 1
extern void CommandLineParserInit(void);
extern void CommandLineParserProcess(void);
//Function from Ass_1 Question 4
extern uint8_t string_parser(uint8_t *inp, uint8_t **array_of_words[]);

//Command Line Calculator Functions
int8_t Add_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);
int8_t Sub_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);
int8_t Mul_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);
int8_t Div_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);
int8_t Help_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);
int8_t Debug_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);
int8_t Clear_Function(uint8_t ArgNum, uint8_t *ArgStrings[]);

// Question 2
extern void CalculatorInit(void);
extern void CalculatorProcess(void);

//LCD Calculator Functions
void DrawButton(uint8_t DrawButton, uint8_t Toggle);
int8_t FindPress(uint16_t X_Pos, uint16_t Y_Pos);
void Print_To_Screen(uint8_t *String_p, uint8_t Button);
void Clear_Button(uint8_t Button);
void Clear_Array(uint8_t *Array_p);

float Calc_0(uint8_t *arg1, uint8_t *arg2);
float Calc_Add(uint8_t *arg1, uint8_t *arg2);
float Calc_Sub(uint8_t *arg1, uint8_t *arg2);
float Calc_Mul(uint8_t *arg1, uint8_t *arg2);
float Calc_Div(uint8_t *arg1, uint8_t *arg2);
float Calc_Mod(uint8_t *arg1, uint8_t *arg2);

void Sexy_Draw(void);


// Library functions
extern uint8_t BSP_TP_Init(void);
extern uint8_t BSP_TP_GetDisplayPoint(Coordinate *pDisplay);

#endif /* ASS_02_H_ */

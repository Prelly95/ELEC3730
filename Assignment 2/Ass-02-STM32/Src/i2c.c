/*
 * i2c.c
 *
 *  Created on: 26 Apr 2017
 *      Author: c3229056
 */



#include "Ass-02.h"

void Sexy_Draw(void)
{
	uint8_t message = 0;
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(0, 0, 320, 240);

	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	message = rand() % 10;

	switch(message){
	case 0:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"OOH(.)(.)", CENTER_MODE);
		break;
	case 1:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"AAAHH", CENTER_MODE);
		break;
	case 2:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"YESSS", CENTER_MODE);
		break;
	case 3:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"NO", CENTER_MODE);
		break;
	case 4:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"HARDER", CENTER_MODE);
		break;
	case 5:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"STOOOOOP :D", CENTER_MODE);
		break;
	case 6:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"i like it ;)", CENTER_MODE);
		break;
	case 7:
		BSP_LCD_SetFont(&Font20);
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"SQUANCH", CENTER_MODE);
		BSP_LCD_SetFont(&Font24);
		break;
	case 8:
		BSP_LCD_SetFont(&Font20);
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"stroke me nicolas cage", CENTER_MODE);
		BSP_LCD_SetFont(&Font24);
		break;
	case 9:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"MORE FINGERS", CENTER_MODE);
		break;
	case 10:
		BSP_LCD_DisplayStringAt(160, 120, (uint8_t*)"MORE LUBE", CENTER_MODE);
		break;
	default:
		break;
	}

}

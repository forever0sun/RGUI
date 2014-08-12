
#ifndef _GUI_PORT_H_
#define _GUI_PORT_H_

#include "stm32f10x.h"
#include "lcd.h"

void GUI_LCDDrier_Init(void);
void GUI_LCDDrier_WritePixel(u16 xpos,u16 ypos,u16 color);
u16  GUI_LCDDrier_ReadPixel(u16 xpos,u16 ypos);


#endif

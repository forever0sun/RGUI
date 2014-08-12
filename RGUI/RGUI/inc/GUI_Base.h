
#ifndef _GUI_BASE_H_
#define _GUI_BASE_H_

#include "GUI_Port.h"
#include "GUI_Font.h"

typedef struct
{
    u16 Point;
    u16 Pen;	//»­±ÊÑÕÉ«
    u16 Back;   //±³¾°É« 
}GUI_COLOR_t;

extern GUI_COLOR_t GUI_Color;

void GUI_Init(void);

void GUI_SetFont(FONT_ITEM font);
void GUI_ShowString(u16 x0 , u16 y0 ,const u8 *pstr);

u16  GUI_GetPenColor(void);
void GUI_SetPenColor(u16 color);
u16  GUI_GetBackColor(void);
void GUI_SetBackColor(u16 color);

void GUI_DrawPoint(u16 x0 , u16 y0);
void GUI_DrawLine( u16 x0 , u16 y0, u16 x1 ,u16 y1);
void GUI_DrawRect( u16 x0 , u16 y0 , u16 xlen , u16 ylen);
void GUI_DrawRectFill(u16 x0 , u16 y0 , u16 xlen , u16 ylen);


#endif




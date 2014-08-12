
#include "GUI_Base.h"
#include "GUI_Font.h"


static FONT_ITEM GUI_Font ;//= FontAscII_6x12;

void GUI_SetFont(FONT_ITEM font)
{
	GUI_Font = font;
}



void GUI_ShowChar(u16 x0 , u16 y0 ,u8 ch)
{
	u8 i,j;
    u8 temp;    
    u8 x=x0,y=y0;
	const u8 *pdata;
    
    if((ch<' ')||(ch>'~'))  return;
    
    pdata = GUI_Font.pFontData + GUI_Font.ysize*( ch-' ');

	for(i=0 ; i<GUI_Font.ysize ; i++)
	{
        temp = *pdata++;    
		for(j=0 ; j<GUI_Font.xsize ; j++)
		{
            if(temp&0x80)
            {
                GUI_Color.Point = GUI_Color.Pen;
                GUI_DrawPoint(x,y);
            }
            else
            {
                GUI_Color.Point = GUI_Color.Back;
                GUI_DrawPoint(x,y);
            }
            x++;
			temp<<=1;
		}
        x= x0;
        y++;
	}

}

void GUI_ShowString(u16 x0 , u16 y0 ,const u8 *pstr)
{
    while(*pstr)
    {
        GUI_ShowChar(x0,y0,*pstr++);
        x0+=GUI_Font.xsize;
    }
}


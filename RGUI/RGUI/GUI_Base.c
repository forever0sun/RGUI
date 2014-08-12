
#include "GUI_Base.h"

//���廭��ȫ�ֱ���
GUI_COLOR_t GUI_Color;

void GUI_Init(void)
{
    GUI_LCDDrier_Init();
    GUI_SetPenColor(BLACK);
    GUI_SetBackColor(WHITE);
}

void GUI_DrawPoint(u16 x0,u16 y0)
{
    GUI_LCDDrier_WritePixel(x0,y0,GUI_Color.Point);
}

void GUI_DrawLine(u16 x0,u16 y0,u16 x1,u16 y1)
{
    u16 i,len;
    if(x0 == x1)            //ˮƽ��
    {
        len = y1 -y0;
        for(i=0; i<len ;i++)
        {
            GUI_LCDDrier_WritePixel(x0,y0+i,GUI_Color.Pen);
        }
    }
    else if(y0 == y1)       //��ֱ��
    {
        len = x1 -x0;
        for(i=0; i<len ;i++)
        {
            GUI_LCDDrier_WritePixel(x0+i,y0,GUI_Color.Pen);
        }    
    }
    else
    {
        //....  ����ֱ�� ���޴���
    }

}

                                                                                
/*******************************************************************************
**��	��: GUI_GetPenColor()
**��	��: ��ȡ������ɫ
**��	��: ��
**��	�أ�������ɫֵ
*******************************************************************************/
u16 GUI_GetPenColor(void)
{
    return GUI_Color.Pen;
}

/*******************************************************************************
**��	��: GUI_SetPenColor()
**��	��: ���û�����ɫ
**��	��: color   -- ������ɫֵ
**��	�أ��� 
*******************************************************************************/
void GUI_SetPenColor(u16 color)
{
    GUI_Color.Pen = color;
}

/*******************************************************************************
**��	��: GUI_GetBackColor()
**��	��: ��ȡ������ɫ
**��	��: ��
**��	�أ����ʱ�����ɫֵ
*******************************************************************************/
u16 GUI_GetBackColor(void)
{
    return GUI_Color.Back;
}

/*******************************************************************************
**��	��: GUI_SetBackColor()
**��	��: ���ñ�����ɫ
**��	��: color   -- ������ɫֵ
**��	�أ��� 
*******************************************************************************/
void GUI_SetBackColor(u16 color)
{
    GUI_Color.Back = color;
}

/*******************************************************************************
**��	��: GUI_DrawRect()
**��	��: �����ο�
**��	��: x0      -- ��������
            y0      -- ���������
            xlen    -- ���򳤶�
            ylen    -- ���򳤶�
**��	�أ��� 
*******************************************************************************/
void GUI_DrawRect(u16 x0 , u16 y0 , u16 xlen , u16 ylen)
{
    GUI_DrawLine(x0     ,y0     ,x0+xlen    ,y0     );
    GUI_DrawLine(x0     ,y0     ,x0         ,y0+ylen);
    GUI_DrawLine(x0+xlen,y0     ,x0+xlen    ,y0+ylen);
    GUI_DrawLine(x0     ,y0+ylen,x0+xlen    ,y0+ylen);
}

/*******************************************************************************
**��	��: GUI_DrawRect()
**��	��: ��������
**��	��: x0      -- ��������
            y0      -- ���������
            xlen    -- ���򳤶�
            ylen    -- ���򳤶�
**��	�أ��� 
*******************************************************************************/
void GUI_DrawRectFill(u16 x0 , u16 y0 , u16 xlen , u16 ylen)
{
    u32 i=0;
    while(i<ylen)						
    {  
       GUI_DrawLine(x0 , y0+i , x0+xlen , y0+i );
       i++;							
    }
}


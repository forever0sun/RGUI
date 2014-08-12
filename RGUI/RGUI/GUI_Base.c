
#include "GUI_Base.h"

//定义画笔全局变量
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
    if(x0 == x1)            //水平线
    {
        len = y1 -y0;
        for(i=0; i<len ;i++)
        {
            GUI_LCDDrier_WritePixel(x0,y0+i,GUI_Color.Pen);
        }
    }
    else if(y0 == y1)       //垂直线
    {
        len = x1 -x0;
        for(i=0; i<len ;i++)
        {
            GUI_LCDDrier_WritePixel(x0+i,y0,GUI_Color.Pen);
        }    
    }
    else
    {
        //....  其他直线 暂无处理
    }

}

                                                                                
/*******************************************************************************
**函	数: GUI_GetPenColor()
**功	能: 获取画笔颜色
**参	数: 无
**返	回：画笔颜色值
*******************************************************************************/
u16 GUI_GetPenColor(void)
{
    return GUI_Color.Pen;
}

/*******************************************************************************
**函	数: GUI_SetPenColor()
**功	能: 设置画笔颜色
**参	数: color   -- 画笔颜色值
**返	回：无 
*******************************************************************************/
void GUI_SetPenColor(u16 color)
{
    GUI_Color.Pen = color;
}

/*******************************************************************************
**函	数: GUI_GetBackColor()
**功	能: 获取背景颜色
**参	数: 无
**返	回：画笔背景颜色值
*******************************************************************************/
u16 GUI_GetBackColor(void)
{
    return GUI_Color.Back;
}

/*******************************************************************************
**函	数: GUI_SetBackColor()
**功	能: 设置背景颜色
**参	数: color   -- 画笔颜色值
**返	回：无 
*******************************************************************************/
void GUI_SetBackColor(u16 color)
{
    GUI_Color.Back = color;
}

/*******************************************************************************
**函	数: GUI_DrawRect()
**功	能: 画矩形框
**参	数: x0      -- 起点横坐标
            y0      -- 起点纵坐标
            xlen    -- 横向长度
            ylen    -- 纵向长度
**返	回：无 
*******************************************************************************/
void GUI_DrawRect(u16 x0 , u16 y0 , u16 xlen , u16 ylen)
{
    GUI_DrawLine(x0     ,y0     ,x0+xlen    ,y0     );
    GUI_DrawLine(x0     ,y0     ,x0         ,y0+ylen);
    GUI_DrawLine(x0+xlen,y0     ,x0+xlen    ,y0+ylen);
    GUI_DrawLine(x0     ,y0+ylen,x0+xlen    ,y0+ylen);
}

/*******************************************************************************
**函	数: GUI_DrawRect()
**功	能: 画填充矩形
**参	数: x0      -- 起点横坐标
            y0      -- 起点纵坐标
            xlen    -- 横向长度
            ylen    -- 纵向长度
**返	回：无 
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


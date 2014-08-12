
#ifndef _GUI_FONT_H_
#define _GUI_FONT_H_

#define ASCII_TAB_SIZE  95

typedef struct 
{
	unsigned char  xsize;
	unsigned char  ysize;
	const unsigned char  *pFontData;
}FONT_ITEM;

//    char b[10][10];
//    char *pb = &b[0][0];
//    
//    *(pb+10*2+3) = 0x55;

extern FONT_ITEM FontAscII_6x12;
extern FONT_ITEM FontAscII_8x16;

#endif

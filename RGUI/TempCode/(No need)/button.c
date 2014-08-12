//按钮控件主体(控件类实现过程):

/*============================================================================*/

#define        BS_PRESSED        (1<<0)

/*============================================================================*/
//按钮风格

#define        BS_NULL                (0<<0)
#define        BS_IMG                (1<<1)

/*============================================================================*/

static        int        PaintButton(HDC hdc,HWND hwnd)
{
        WINDOW *pBN;
        GUI_COLOR        fr_color,bk_color,bd_color;
        COORD x,y;
        ////
        
        if(hdc==0)        return 0;
        if(hwnd==0)        return 0;
        
        pBN                        =HWND2WND(hwnd);
        fr_color        =pBN->FrColor;
        bk_color        =pBN->BkColor;
        bd_color        =pBN->BdColor;
        
        x=0;
        y=0;

        if(WindowStyle(hwnd,BS_NULL))
        {
                FillRaisedRectangle(hdc,x,y,pBN->Rect.dx,pBN->Rect.dy,bk_color);
                DrawImage(hdc,x,y,pBN->hImage);
                Label(hdc,x,y,pBN->Rect.dx,pBN->Rect.dy,fr_color,RGB_TRANS,RGB_TRANS,CENTER,pBN->Caption);

        }
        ////
        
        if(WindowStyle(hwnd,BS_IMG))
        {
                IMG_BUTTON_DATA *btn_data;
                ////
                btn_data        =(void*)GetWindowPrivateData(hwnd);
                DrawImage(hdc,x,y,btn_data->hImg);
        
        }
        
        
        ////
        if(WindowStatus(hwnd,WS_FOCUS))
        {
                //如果是焦点窗口
                DotRectangle(hdc,x+3,y+3,pBN->Rect.dx-6,pBN->Rect.dy-6,fr_color);
        }

}

/*============================================================================*/

static        int        PaintPressedButton(HDC hdc,HWND hwnd)
{
        WINDOW *pBN;
        GUI_COLOR        fr_color,bk_color,bd_color;
        COORD x,y;
        ////
        
        if(hdc==0)        return 0;
        if(hwnd==0)        return 0;
        
        pBN                        =HWND2WND(hwnd);
        fr_color        =pBN->FrColor;
        bk_color        =pBN->BkColor;
        bd_color        =pBN->BdColor;
        
        //x        =pBN->Rect.x;
        //y        =pBN->Rect.y;
        x=0;
        y=0;
        if(WindowStyle(hwnd,BS_NULL))
        {
                FillSunkRectangle(hdc,x,y,pBN->Rect.dx,pBN->Rect.dy,AlphaBlendColor((RGB(0,0,0)),bk_color,96));
                Label(hdc,x+3,y+3,pBN->Rect.dx-3,pBN->Rect.dy-3,fr_color,RGB_TRANS,RGB_TRANS,CENTER,pBN->Caption);

        }
        ////
        
        if(WindowStyle(hwnd,BS_IMG))
        {
                IMG_BUTTON_DATA *btn_data;
                ////
                btn_data        =(void*)GetWindowPrivateData(hwnd);
                DrawImage(hdc,x,y,btn_data->hPressedImg);
        
        }

}

/*============================================================================*/

static        int        ButtonDraw(HDC hdc,HWND hwnd)
{

        if(WindowStatus(hwnd,BS_PRESSED))
        {
                
                PaintPressedButton(hdc,hwnd);
        }        
        else
        {
                PaintButton(hdc,hwnd);
        }
        
        InvalidateRect(hwnd,0,0);

//        DebugPrintf("%s -> OnDraw!\n",pBN->Caption);
}

/*============================================================================*/

static        int ButtonRelease(HWND hwnd)
{
        
        WINDOW *pWin;
        ////
        
        if(hwnd==0)        return 0;
        pWin=HWND2WND(hwnd);
        
#if        GUI_DBG_EN
        DebugPrintf("ButtonRelease => '%s' - %08XH\n",pWin->Caption,pWin);
#endif        

        //发送MSG_CLOSE所有子窗口.
        pWin=HWND2WND(pWin->hChild);
        while(pWin)
        {
                SendMessage(WND2HWND(pWin),MSG_CLOSE,0,0);
                pWin=pWin->Next;
        }
        
        
        MemFree((void*)hwnd);
        return        1;
        
}

/*============================================================================*/

static        U32 ButtonProc(HWND hwnd,U32 msg,WPARAM wParam,LPARAM lParam)
{
        HDC        hdc;
        ////

        switch(msg)
        {
                
                case        MSG_CREATE:
                                
                                break;
                                ////
                
                case        MSG_LBUTTONDOWN:

                                        
                        //        DebugPrintf("'%s' -> MSG_LBUTTONDOWN - %d,%d\n",pBN->Caption,wParam>>16,wParam&0xffff);

                                if(!WindowStatus(hwnd,BS_PRESSED))        
                                {
                                        SetWindowStatus(hwnd,BS_PRESSED);
                                        InvalidateRect(hwnd,0,0);
                                        UpdateWindow(hwnd);
                                                
                                        KillFocus(GetFocus(hwnd));
                                }
                                        
                                if(WindowStyle(hwnd,WS_NCCHILD))
                                {
                                        SendMessageToParent(hwnd,MSG_SYSCOMMAND,(BN_CLICKED<<16)|GetWindowID(hwnd),hwnd);
                                }
                                else
                                {
                                        SendMessageToParent(hwnd,MSG_COMMAND,(BN_CLICKED<<16)|GetWindowID(hwnd),hwnd);
                                }
                                
                                break;
                                ////////
                
                case        MSG_KILLFOCUS:
                                
                //                DebugPrintf("'%s' -> MSG_KILLFOCUS\n",pBN->Caption);
                                break;
                                ////////
                                
                case        MSG_SETFOCUS:
                
                //                DebugPrintf("'%s' -> MSG_SETFOCUS\n",pBN->Caption);
                                break;
                                ////////
                                        
                case        MSG_LBUTTONUP:
                
                                
                                ClrWindowStatus(hwnd,BS_PRESSED);        
                                        
                        //        DebugPrintf("'%s' -> MSG_LBUTTONUP - %d,%d\n",pBN->Caption,wParam>>16,wParam&0xffff);
                                InvalidateRect(hwnd,0,0);
                                UpdateWindow(hwnd);
                                if(WindowStyle(hwnd,WS_NCCHILD))
                                {
                                        SendMessageToParent(hwnd,MSG_SYSCOMMAND,(BN_UP<<16)|GetWindowID(hwnd),hwnd);
                                }
                                else
                                {
                                        SendMessageToParent(hwnd,MSG_COMMAND,(BN_UP<<16)|GetWindowID(hwnd),hwnd);
                                }
                                break;
                                
                                ///////
                
                case        BM_SETIMAGE:
                                if(WindowStyle(hwnd,BS_IMG))
                                {
                                        IMG_BUTTON_DATA *btn;
                                        /////
                                        
                                        btn=(void*)GetWindowPrivateData(hwnd);
                                        if(btn)
                                        {
                                                btn->hImg                        =(HANDLE)wParam;
                                                btn->hPressedImg        =(HANDLE)lParam;
                                        }
                                }
                                break;
                                ////
                                
                case        BM_GETIMAGE:
                
                                break;
                                ////
                                                
                case        MSG_PAINT:
                                                        
                        //        DebugPrintf("'%s' -> MSG_PAINT\n",pBN->Caption);

                                hdc        =BeginPaint(hwnd);
                                if(hdc==0)        break;        
                                                
                                
                                ButtonDraw(hdc,hwnd);
                                
                                EndPaint(hwnd,hdc);
                                break;
                                ////////
                                
                case        MSG_DESTROY:
                                
                                ButtonRelease(hwnd);
                                break;
                                ///////////
                                
                default:
                                return        DefaultWindowProc(hwnd,msg,wParam,lParam);
                                break;

        }

        return        MSG_NULL;
}

/*============================================================================*/

/*============================================================================*/

static        WNDCLASS wnd_class;

void        RegisButtonClass(void)
{
        ////
        
        wnd_class.ClassName        ="button";
        wnd_class.Type                =WIN_TYPE_WIDGET;
        wnd_class.Style                =0;
        wnd_class.Proc                =ButtonProc;
        RegisterWindowClass(&wnd_class);
        
}

/*============================================================================*/
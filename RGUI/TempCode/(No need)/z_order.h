
#define EN_ORDER 1

typedef struct
{
	unsigned int x_min;
	unsigned int y_min;
	unsigned int x_max;
	unsigned int y_max;
}rectangle;

typedef struct
{
	unsigned int x;
	unsigned int y;

}coordinate;


typedef struct
{
	//...

}control;

typedef struct
{
	struct window * pnext;
	struct coordinate coord;//窗口位置
	struct rectangle * prect;//窗口剪切域(矩形链表头指针)

	struct window * psubwindow;

	struct control * pcontrol;

	//......

}window;

typedef window * hwin;

#ifndef IN_ORDER


	extern void init_z_order();
	extern void del_node(hwin hw);
	extern void void add_node_front(hwin hw);



#endif

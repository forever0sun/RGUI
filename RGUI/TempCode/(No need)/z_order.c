
#define IN_ORDER

#include "z_order.h"


#if EN_ORDER > 0

	window * pwin;

	void init_z_order()
	{
		pwin = 0;

	}

	void del_node(hwin hw)//ɾ��һ��ָ���ڵ�
	{
		window * px;
		window * p;

		px = pwin;
		p = pwin;
		
		if (px == hw) 
		{

			pwin = (window *)px ->pnext;

		}else
		{
			px = (window *)px ->pnext;


			while (px) 
			{
				if (px == hw) 
				{

					(window *)p ->pnext = (window *)px ->pnext;
					break;
				}

				px = (window *)px ->pnext;
				p = (window *)p ->pnext;
			}
		}
	}





	void add_node_front(hwin hw)//���һ���ڵ㣬���ӵ�ͷ��
	{

		(window *)hw->pnext = pwin;
		pwin = hw;
	}



	
#endif







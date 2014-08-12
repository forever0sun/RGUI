

#define IN_MEM



#include "memory.h"


#if EN_MEM > 0


	void MemInit(OS_MEM * mem,unsigned char N_BLOCKS,unsigned char block_size,void * buf)
	{

		mem -> N_BLOCKS = N_BLOCKS;
		mem -> block_size = block_size;
		mem -> buf = buf;	

	}


	void * AllocMem(OS_MEM * mem)
	{
		unsigned char n;
		for (n = 0; n < M_T_SIZE * M_M_WIDE; n ++) 
		{
			if (n > mem -> N_BLOCKS) return 0;
			
			if ((mem -> m_table[n/M_M_WIDE] & (1 << (n%M_M_WIDE))) == 0) 
			{
				mem -> m_table[n/M_M_WIDE] |= (1 << (n%M_M_WIDE));

				return (mem -> buf + mem -> block_size * n);
			}
		}

		return 0;
	}


	void FreeMem(OS_MEM * pmem, void * addr)
	{
		unsigned char m;
		m = (addr - pmem -> buf)/pmem -> block_size;
		if (m < M_T_SIZE*M_M_WIDE) 
		{
			pmem -> m_table[m/M_M_WIDE] &= ~((1 << (m%M_M_WIDE)));
		}

	}



#endif
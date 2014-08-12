

#define OS_MEM_EN 1

	#define M_T_SIZE 3				//内存块表尺寸
	#define M_M_WIDE 32				//成员位宽

typedef struct
{
	unsigned char N_BLOCKS;					//实际内存块数
	unsigned char block_size;				//每块尺寸
	unsigned int m_table[M_T_SIZE];			//内存块可登记数=内存块表尺寸*成员位宽
	void * buf;								//内存首地址
}OS_MEM;

#ifndef IN_MEM



	#if OS_MEM_EN > 0
		
		extern 	void MemInit(OS_MEM * mem,unsigned char N_BLOCKS,unsigned char block_size,void * buf);
		extern 	void * AllocMem(OS_MEM * mem);
		extern 	void FreeMem(OS_MEM * pmem, void * addr);
	#endif

#endif

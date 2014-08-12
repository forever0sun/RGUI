

#define OS_MEM_EN 1

	#define M_T_SIZE 3				//�ڴ���ߴ�
	#define M_M_WIDE 32				//��Աλ��

typedef struct
{
	unsigned char N_BLOCKS;					//ʵ���ڴ����
	unsigned char block_size;				//ÿ��ߴ�
	unsigned int m_table[M_T_SIZE];			//�ڴ��ɵǼ���=�ڴ���ߴ�*��Աλ��
	void * buf;								//�ڴ��׵�ַ
}OS_MEM;

#ifndef IN_MEM



	#if OS_MEM_EN > 0
		
		extern 	void MemInit(OS_MEM * mem,unsigned char N_BLOCKS,unsigned char block_size,void * buf);
		extern 	void * AllocMem(OS_MEM * mem);
		extern 	void FreeMem(OS_MEM * pmem, void * addr);
	#endif

#endif

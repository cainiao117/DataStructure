#define _CRT_SECURE_NO_WARNINGS 1

#include "homework_1.h"


int main()
{
	PNode L = LinkList_TailInsert();//创建链表;
	Show(L);//显示链表元素
	//Free(L);//释放空间；
	//Show(L);
	Delete_x(L, 3);//删除链表中所有元素为3的节点；
	printf("\n");
	Show(L);
	return 0;
}
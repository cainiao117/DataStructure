#define _CRT_SECURE_NO_WARNINGS 1

#include "homework_1.h"


int main()
{
	PNode L = LinkList_TailInsert();//��������;
	Show(L);//��ʾ����Ԫ��
	//Free(L);//�ͷſռ䣻
	//Show(L);
	Delete_x(L, 3);//ɾ������������Ԫ��Ϊ3�Ľڵ㣻
	printf("\n");
	Show(L);
	return 0;
}
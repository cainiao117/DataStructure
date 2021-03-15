#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//问题描述：对于长度为n的顺序表L,编写一个时间复杂度为o(n)，空间复杂度为o(1)的算法，该算法删除线性表中所有值为x的元素

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int SqL_Del(SqList* pL, ElemType e);

int main()
{
	SqList L;
	L.length = 10;
	int i;
	for (i = 0; i < L.length; i++)
	{
		if ((i == 3) || (i == 5) || (i == 7))
		{
			L.data[i] = 13;
		}
		else
		{
			L.data[i] = i;
		}
	}
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	SqL_Del(&L, 13);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	SqL_Del(&L, 13);

	return 0;
}

int SqL_Del(SqList* pL, ElemType e)
{
	//该函数删除顺序表中所有元素为e的元素，完成返回0，否则返回-1；
	if (pL->length < 1)
	{
		printf("顺序表为空\n");
		return -1;
	}
	int count = 0;//记录顺序表中所有元素为e的个数
	int i;
	for (i = 0; i < pL->length; i++)
	{
		if (pL->data[i] == e)
		{
			count++;
		}
		else
		{
			pL->data[i-count] = pL->data[i];
		}
	}
	pL->length -= count;
	return 0;
}
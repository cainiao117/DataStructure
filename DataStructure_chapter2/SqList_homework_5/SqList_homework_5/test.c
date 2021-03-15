#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//从顺序表中删除其值在给定值s和t之间的所有元素

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int SqL_Del(SqList* pL, ElemType s, ElemType t);

int main()
{
	
	SqList L;
	L.length = 10;
	int i;
	for (i = 0; i < L.length; i++)
	{
		L.data[i] = i;
	}
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	SqL_Del(&L, 2, 5);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
	printf("L.length==%d\n", L.length);

	return 0;
}

int SqL_Del(SqList* pL, ElemType s, ElemType t)
{
	//从顺序表中删除其值在给定值s和t之间的所有元素,删除成功返回0，否则返回-1；
	if ((pL->length < 0) || (s >= t))
	{
		return -1;
	}
	int count=0;//统计在定值s和t之间的元素的个数。
	int i;
	for (i = 0; i < pL->length; i++)
	{
		if ((pL->data[i] >= s) && (pL->data[i] <= t))
		{
			count++;
		}
		else
		{
			pL->data[i - count] = pL->data[i];
		}
	}
	pL->length = pL->length - count;
	return 0;
}
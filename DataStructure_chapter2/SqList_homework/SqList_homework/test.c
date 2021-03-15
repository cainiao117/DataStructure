#define _CRT_SECURE_NO_WARNINGS 1
//问题描述：从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除的元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示错位信息并退出运行

#include <stdio.h>

#define Max_Size 100
typedef int ElemType;

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int ListDelete_min(SqList* pL);
int LocateElem(SqList* pL, ElemType e);

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

	ElemType min= ListDelete_min(&L);
	printf("min=%d\n", min);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}

	return 0;
}

int ListDelete_min(SqList* pL)
{
	//该函数用于解决上方所描述的问题；
	if (pL->length < 1)
	{
		printf("顺序表内没有元素");
		return -1;//顺序表为空返回-1；
	}
	ElemType min=pL->data[0];
	int i;
	for (i = 0; i < pL->length; i++)
	{
		if (pL->data[i] < min)
		{
			min = pL->data[i];
		}
	}
	int Location = LocateElem(pL, min);
	pL->data[Location - 1] = pL->data[pL->length - 1];
	return min;
}

int LocateElem(SqList* pL, ElemType e)
{
	int i;
	for (i = 0; i < pL->length; i++)
	{
		if (pL->data[i] == e)
		{
			return i + 1;
		}
	}
	return -1;
}
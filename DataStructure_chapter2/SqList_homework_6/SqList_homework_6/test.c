#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//问题描述：从有序顺序表中删除所有其值重复的元素，使得表中所有元素不相同

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int SqL_Del(SqList* pL);

int main()
{

	SqList L;
	L.length = 11;
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (i == 0)
		{
			L.data[i] = 1;
		}
		else if ((i >= 1) && (i <= 4))
		{
			L.data[i] = 2;
		}
		else if ((i >= 5) && (i <= 7))
		{
			L.data[i] = 3;
		}
		else if ((i >= 8) && (i <= 9))
		{
			L.data[i] = 4;
		}
		else
		{
			L.data[i] = 5;
		}

	}
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	SqL_Del(&L);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
	printf("L.length==%d\n", L.length);

	return 0;
}


int SqL_Del(SqList* pL)
{
	//从有序顺序表中删除所有其值重复的元素，使得表中所有元素不相同,删除成功返回0，否则返回-1
	if (pL->length < 0)
	{
		printf("顺序表为空表\n");
		return -1;
	}
	int count = 0;//统计不同元素相等的个数之和；
	int i;
	for (i = 0; i < pL->length; i++)
	{
		if (pL->data[i] == pL->data[i + 1])
		{
			count++;
		}
		else
		{
			pL->data[i - count] = pL->data[i];
		}
	}
	pL->length -= count;
	return 0;

}
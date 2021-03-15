#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100
typedef int ElemType;

#include <stdio.h>
//问题描述：已知在一维数组A[m+n]中依次存放两个线性表（a1，a2,,,am）和（b1,b2,,,bn）编写算法，使得数组中两个顺序表的位置互换
//即（b1,b2,,,bn）在（a1，a2,,,am）前面

typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

int SqL_Rverse(SqList* pL, int n1, int n2);
int Rverse(SqList* pL, int a, int b);

int main()
{
	SqList L;
	L.length = 15;
	int i;
	for (i = 0; i < L.length; i++)
	{
		L.data[i] = i;
	}
	for (i = 0; i < L.length; i++)
	{
		printf("%-3d ", L.data[i]);
	}
	printf("\n");

	SqL_Rverse(&L, 5, 10);
	/*Rverse(&L, 0, 14);
	Rverse(&L, 0, 9);
	Rverse(&L, 10, 14);*/
	for (i = 0; i < L.length; i++)
	{
		printf("%-3d ", L.data[i]);
	}
	printf("\n");

	return 0;
}

int SqL_Rverse(SqList* pL, int n1, int n2)
{
	if (pL->length < 0)
	{
		return -1;
	}
	Rverse(pL, 0, pL->length - 1);
	Rverse(pL, 0, n2 - 1);
	Rverse(pL, pL->length-n1, pL->length - 1);
	return 0;
}

int Rverse(SqList* pL, int a, int b)
{
	if (pL->length < 0)
	{
		return -1;
	}
	int left = a;
	int right = b;
	while (left < right)
	{
		ElemType temp = pL->data[left];
		pL->data[left] = pL->data[right];
		pL->data[right] = temp;
		left++;
		right--;
	}
	return 0;
}


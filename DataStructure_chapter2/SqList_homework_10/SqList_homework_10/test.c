#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 100

#include <stdio.h>
//n个整数存放在一维数组中，如（x0,x1,x2,x3,,,xn-1）,将其变换为（xp,xp+1,,,xn-1,x0,x1,x2,,,xp-1）

typedef int ElemType;

typedef struct{
	ElemType data[MAX_SIZE];
	int length;
}SqList;

int SqL_Reverse(SqList* pL, int n);
int Rverse(SqList* pL, int a, int b);

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

	SqL_Reverse(&L, 7);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	return 0;
}

int SqL_Reverse(SqList* pL, int n)
{
	if (pL->length < 1)
	{
		return -1;
	}
	Rverse(pL, 0, pL->length - 1);
	Rverse(pL, 0, pL->length-n - 1);
	Rverse(pL, pL->length - n, pL->length - 1);
	return 0;
}

int Rverse(SqList* pL, int a, int b)
{
	if (pL->length < 1)
	{
		return -1;
	}
	int left = a, right = b;
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
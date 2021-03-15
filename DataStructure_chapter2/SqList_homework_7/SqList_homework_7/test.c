#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//问题描述，将两个有序顺序表合并为一个新的有序顺序表，并且由函数返回结果顺序表

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int Merge(SqList* pL1, SqList* pL2, SqList* pL3);

int main()
{
	SqList L1, L2;
	L1.length = 5;
	L2.length = 10;
	int i;
	for (i = 0; i < L1.length; i++)
	{
		L1.data[i] = 3 + i;
	}
	for (i = 0; i < L2.length; i++)
	{
		L2.data[i] = i;
	}
	for (i = 0; i < L1.length; i++)
	{
		printf("%d ", L1.data[i]);
	}
	printf("\n");
	for (i = 0; i < L2.length; i++)
	{
		printf("%d ", L2.data[i]);
	}
	printf("\n");

	SqList L3;
	L3.length = 0;
	Merge(&L1, &L2, &L3);
	for (i = 0; i < L3.length; i++)
	{
		printf("%d ", L3.data[i]);
	}
	printf("L3.length==%d\n",L3.length);
	return 0;
}

int Merge(SqList* pL1, SqList* pL2, SqList* pL3)
{
	//将两个有序顺序表合并为一个新的有序顺序表，并且由函数返回结果顺序表
	if ((pL1->length < 1) || (pL2->length < 1))
	{
		return -1;
	}
	int i = 0, j = 0, k = 0;
	while ((i < pL1->length) && (j < pL2->length))
	{
		if (pL1->data[i] <= pL2->data[j])
		{
			pL3->data[k] = pL1->data[i];
			i++;
		}
		else
		{
			pL3->data[k] = pL2->data[j];
			j++;
		}
		k++;
	}
	while (i < pL1->length)
	{
		pL3->data[k++] = pL1->data[i++];
	}
	while (j < pL2->length)
	{
		pL3->data[k++] = pL2->data[j++];
	}
	pL3->length =k;
	return 0;
}

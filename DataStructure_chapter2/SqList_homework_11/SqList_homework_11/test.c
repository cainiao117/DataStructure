#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
#define LENGTH 5

#include <stdio.h>

typedef int ElemType;
typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int Find_Mid(SqList* pL1, SqList* pL2);

int main()
{
	SqList L1, L2;
	L1.length = LENGTH;
	L2.length = LENGTH;
	int i;
	for (i = 0; i < LENGTH; i++)
	{
		L1.data[i] = 11+2 * i;
	}
	for (i = 0; i < LENGTH; i++)
	{
		if (i == LENGTH - 1)
		{
			L2.data[i] = 20;
		}
		else
		{
			L2.data[i] = 2 * (i + 1);
		}
	}
	for (i = 0; i < LENGTH; i++)
	{
		printf("%3d ", L1.data[i]);
	}
	printf("\n");
	for (i = 0; i < LENGTH; i++)
	{
		printf("%3d ", L2.data[i]);
	}
	printf("\n");
	
	printf("Mid==%d\n",Find_Mid(&L1, &L2));

	return 0;
}

int Find_Mid(SqList* pL1, SqList* pL2)
{
	if ((pL1->length < 0) || (pL2->length < 0))
	{
		return -1;
	}
	int i = 0, j = 0,count =0;
	ElemType temp;
	while ((i < pL1->length) && (j < pL2->length))
	{
		if (count == (pL1->length + pL2->length) / 2 + (pL1->length + pL2->length) % 2)
		{
			return temp;
		}
		if (pL1->data[i] < pL2->data[j])
		{
			temp = pL1->data[i];
			i++;
			count++;
		}
		else
		{
			temp = pL2->data[j];
			j++;
			count++;
		}
	}
	while (i < pL1->length)
	{
		if (count == (pL1->length + pL2->length) / 2 + (pL1->length + pL2->length) % 2)
		{
			return temp;
		}
		temp = pL1->data[i];
		i++;
		count++;
	}
	while (j < pL2->length)
	{
		if (count == (pL1->length + pL2->length) / 2 + (pL1->length + pL2->length) % 2)
		{
			return temp;
		}
		temp = pL2->data[j];
		j++;
		count++;
	}
}
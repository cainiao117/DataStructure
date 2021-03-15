#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MaxSize 100//定义数组最大存储元素为100个
typedef int ElemType;//数组内元素类型为整形

typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

int ListInsert(SqList* pL, int i, ElemType e);
int ListDelete(SqList* pL, int i);
int LocateElem(SqList* pL, ElemType e);


int main()
{
	SqList L;
	L.length = 10;//原顺序表内存储有10个元素
	int i;
	for (i = 0; i < 10; i++)
	{
		L.data[i] = i;//初始化顺序表内元素
	}
	/*for (i = 0; i < 10; i++)
	{
		printf("%d ", L.data[i]);
	}*/

	ListInsert(&L, 5, 33);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
	ListDelete(&L, 5);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
	int Location = LocateElem(&L, 5);
	printf("Location==%d\n", Location);

	return 0;
}

int ListInsert(SqList* pL, int i, ElemType e)
{
	//该函数用于对顺序表的插入，其中，指针pL指向被插入的顺序表，i表示插入的位置，e表示插入的元素；
	//如果插入成功返回0，插入失败返回1
	if ((i < 1) || (i>pL->length + 1))
	{
		return 1;
	}
	int j;
	for (j = pL->length; j >= i; j--)
	{
		pL->data[j] = pL->data[j - 1];
	}
	pL->data[i-1] = e;
	pL->length++;//顺序表长度加1；
	return 0;
}

int ListDelete(SqList* pL, int i)
{
	//该函数用于对顺序表的删除，其中，指针pL指向被删除的顺序表，i表示被删除元素的位置。
	//删除成功则返回0，否则返回1；
	if ((i<1) || (i>pL->length))
	{
		return 1;
	}
	int j;
	for (j = i - 1; j < pL->length; j++)
	{
		pL->data[j] = pL->data[j + 1];
	}
	pL->length--;
	return 0;
}

int LocateElem(SqList* pL, ElemType e)
{
	//该函数查找顺序表中第一个元素为e的元素，并且返回其位序（所在数组总的下表加1）
	//如果查找成功返回为序，如果未找到返回-1
	int i;
	for (i = 0; i < pL->length; i++)
	{
		if (pL->data[i] == e)
		{
			return i + 1;
		}
	}
	return - 1;
}


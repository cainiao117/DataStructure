#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//��˳�����ɾ����ֵ�ڸ���ֵs��t֮�������Ԫ��

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
	//��˳�����ɾ����ֵ�ڸ���ֵs��t֮�������Ԫ��,ɾ���ɹ�����0�����򷵻�-1��
	if ((pL->length < 0) || (s >= t))
	{
		return -1;
	}
	int count=0;//ͳ���ڶ�ֵs��t֮���Ԫ�صĸ�����
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
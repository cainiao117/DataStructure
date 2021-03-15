#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//�������������ڳ���Ϊn��˳���L,��дһ��ʱ�临�Ӷ�Ϊo(n)���ռ临�Ӷ�Ϊo(1)���㷨�����㷨ɾ�����Ա�������ֵΪx��Ԫ��

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
	//�ú���ɾ��˳���������Ԫ��Ϊe��Ԫ�أ���ɷ���0�����򷵻�-1��
	if (pL->length < 1)
	{
		printf("˳���Ϊ��\n");
		return -1;
	}
	int count = 0;//��¼˳���������Ԫ��Ϊe�ĸ���
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
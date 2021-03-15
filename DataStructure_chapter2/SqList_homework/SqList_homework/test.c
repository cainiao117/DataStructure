#define _CRT_SECURE_NO_WARNINGS 1
//������������˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾ����Ԫ�ص�ֵ���ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ��λ��Ϣ���˳�����

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
	//�ú������ڽ���Ϸ������������⣻
	if (pL->length < 1)
	{
		printf("˳�����û��Ԫ��");
		return -1;//˳���Ϊ�շ���-1��
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
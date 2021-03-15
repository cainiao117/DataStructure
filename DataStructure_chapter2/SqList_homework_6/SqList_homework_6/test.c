#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//����������������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ�ñ�������Ԫ�ز���ͬ

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
	//������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ�ñ�������Ԫ�ز���ͬ,ɾ���ɹ�����0�����򷵻�-1
	if (pL->length < 0)
	{
		printf("˳���Ϊ�ձ�\n");
		return -1;
	}
	int count = 0;//ͳ�Ʋ�ͬԪ����ȵĸ���֮�ͣ�
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
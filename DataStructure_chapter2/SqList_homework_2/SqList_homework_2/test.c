#define _CRT_SECURE_NO_WARNINGS 1
//������������˳�������Ԫ������Ҫ��ռ临�Ӷ�Ϊo(1)
#include <stdio.h>

#define Max_Size 100
typedef int ElemType;

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int Rverse(SqList* pL);

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

	Rverse(&L);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	return 0;
}

int Rverse(SqList* pL)
{
	//�ú�����������˳����е�����Ԫ�أ�����ʧ�ܷ���-1������ɹ�����0��
	if (pL->length < 1)
	{
		return 1;
	}
	int left = 0, right = pL->length - 1;
	while (left <= right)
	{
		ElemType temp=pL->data[left];
		pL->data[left] = pL->data[right];
		pL->data[right] = temp;
		left++;
		right--;
	}
	return 0;
}
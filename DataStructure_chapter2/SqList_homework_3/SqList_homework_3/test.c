#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����������������˳�����ɾ����ֵ�ڸ���ֵs,t֮�������Ԫ�ء����s,t���������˳���Ϊ�գ���ʾ������Ϣ���˳�����

#define Max_Size 100
typedef int ElemType;

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int Del_List(SqList* pL, int s, int t);

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

	Del_List(&L, 2, 5);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	return 0;
}

int Del_List(SqList* pL, int s, int t)
{
	if (pL->length < 1)
	{
		printf("˳���Ϊ�ձ�\n");
		return -1;
	}
	if (s >= t)
	{
		printf("s��t������Ҫ��\n");
		return -1;
	}
	int i;
	int left, right;
	for (i = 0; i < pL->length; i++)
	{
		if (pL->data[i] >= s)
		{
			left = i;
			break;
		}
	}
	printf("left==%d\n", left);
	for (i = pL->length - 1; i >= 0; i--)
	{
		if (pL->data[i] <= t)
		{
			right = i;
			break;
		}
	}
	printf("right=%d\n", right);
	for (i = 0; i <pL->length-right ; i++)
	{
		pL->data[left + i] = pL->data[right+ 1 + i];
	}
	pL->length = pL->length - (right - left + 1);
	return 0;
}
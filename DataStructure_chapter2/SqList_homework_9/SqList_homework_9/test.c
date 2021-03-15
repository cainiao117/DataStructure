#define _CRT_SECURE_NO_WARNINGS 1
#define Max_Size 100
typedef int ElemType;

#include <stdio.h>
//�������������Ա�Ԫ�ص�������������ʱ�������ֵΪx��Ԫ�أ��ҵ���������λ���ཻ�������Ҳ������������У�ʹ�ñ���Ԫ����Ȼ����

typedef struct{
	ElemType data[Max_Size];
	int length;
}SqList;

int SqL_Search(SqList* pL, ElemType e);
int Insert(SqList* pL, ElemType e, int n);

int main()
{
	SqList L;
	L.length=10;
	int i;
	for (i = 0; i < L.length; i++)
	{
		L.data[i] = 3*i+1;
	}
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");

	int result=SqL_Search(&L, 8);
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
	printf("L.length==%d\n", L.length);
	printf("result ==%d\n", result);

	return 0;
}

int SqL_Search(SqList* pL, ElemType e)
{
	//�ú��������������,�ɹ�����0�����򷵻�-1
	if (pL->length < 1)
	{
		printf("SqList is enpty��\n");
		return -1;
	}
	int left = 0, right = pL->length - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (pL->data[mid] == e)
		{
			return mid;
		}
		else if (pL->data[mid] < e)
		{
			left = mid + 1;
			right--;
		}
		else
		{
			right = mid - 1;
			left++;
		}
		mid = (left + right) / 2;
	}
	Insert(pL,e,mid);
	return 0;
}

int Insert(SqList* pL, ElemType e, int n)
{
	if (pL->length < 1)
	{
		return -1;
	}
	int i;
	for (i = pL->length - 1; i >=n ; i--)
	{
		pL->data[i + 1] = pL->data[i];
	}
	pL->data[n + 1] = e;
	pL->length += 1;
	return 0;
}
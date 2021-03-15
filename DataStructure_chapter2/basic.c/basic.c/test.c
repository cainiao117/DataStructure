#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MaxSize 100//�����������洢Ԫ��Ϊ100��
typedef int ElemType;//������Ԫ������Ϊ����

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
	L.length = 10;//ԭ˳����ڴ洢��10��Ԫ��
	int i;
	for (i = 0; i < 10; i++)
	{
		L.data[i] = i;//��ʼ��˳�����Ԫ��
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
	//�ú������ڶ�˳���Ĳ��룬���У�ָ��pLָ�򱻲����˳���i��ʾ�����λ�ã�e��ʾ�����Ԫ�أ�
	//�������ɹ�����0������ʧ�ܷ���1
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
	pL->length++;//˳����ȼ�1��
	return 0;
}

int ListDelete(SqList* pL, int i)
{
	//�ú������ڶ�˳����ɾ�������У�ָ��pLָ��ɾ����˳���i��ʾ��ɾ��Ԫ�ص�λ�á�
	//ɾ���ɹ��򷵻�0�����򷵻�1��
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
	//�ú�������˳����е�һ��Ԫ��Ϊe��Ԫ�أ����ҷ�����λ�����������ܵ��±��1��
	//������ҳɹ�����Ϊ�����δ�ҵ�����-1
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


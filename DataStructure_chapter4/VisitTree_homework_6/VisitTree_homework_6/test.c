//������������������ȷ��������
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

PT BuildTree(ElemType A[], ElemType B[], int f1, int l1, int f2, int l2);

int main()
{
	return 0;
}

PT BuildTree(ElemType A[], ElemType B[],int f1,int l1,int f2,int l2)//f1����A�ĵ�һ��Ԫ�ص��±�,l1����A�����һ��Ԫ�ص��±�;
{                                                                   //f2����B�ĵ�һ��Ԫ�ص��±�,l2����B�����һ��Ԫ�ص��±�;
	PT p = (PT)malloc(sizeof(TNode));
	p->data = A[f1];
	int end1, end2;//�����һ�������һ������
	for (int i = f2; i <= l2; i++)
	{
		if (B[i] == A[f1])
		{
			end2 = i-1;
			break;
		}
	}
	for (int i = f1 + 1; i <= l1; i++)
	{
		if (A[i] == B[end2])
		{
			end1 = i;
			break;
		}
	}
	
	if (end2 > f2)
	{
		p->lchild = BuildTree(A, B, f1 + 1, end1, f2, end2);
	}
	else
	{
		p->lchild = NULL;
	}

	if (l1 > end1 + 1)
	{
		p->rchild = BuildTree(A, B, end1 + 1, l1, end2 + 2, l2);
	}
	else
	{
		p->rchild = NULL;
	}

	return p;
}
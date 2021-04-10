//根据先序与中序序列确定二叉树
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

PT BuildTree(ElemType A[], ElemType B[],int f1,int l1,int f2,int l2)//f1代表A的第一个元素的下表,l1代表A的最后一个元素的下标;
{                                                                   //f2代表B的第一个元素的下表,l2代表B的最后一个元素的下标;
	PT p = (PT)malloc(sizeof(TNode));
	p->data = A[f1];
	int end1, end2;//代表第一个，最后一个坐标
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
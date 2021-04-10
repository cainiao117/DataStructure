//��ʹ�õݹ���к������:
#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;

typedef struct N{
	PT ptr;
	int tag;
}N;

void visit(PT p);//���������еĲ���;
void PostOrder(PT T)
{
	PT p = T;//T����ָ��������ָ��
	N arr[MAXSIZE];//ջ
	int top = -1;//ָ��ջ����ָ��
	while (p != NULL || top != -1)
	{
		while (p != NULL)
		{
			top++;
			arr[top].ptr = p;
			arr[top].tag = 1;
		}
		while (top != -1 && arr[top].tag == 2)
		{
			visit(arr[top].ptr);
			top--;
		}
		if (top != -1)
		{
			arr[top].tag = 2;
			p = arr[top].ptr->rchild;
		}
	}
}
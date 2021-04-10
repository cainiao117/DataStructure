//不使用递归进行后序遍历:
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

void visit(PT p);//遍历过程中的操作;
void PostOrder(PT T)
{
	PT p = T;//T代表指向树根的指针
	N arr[MAXSIZE];//栈
	int top = -1;//指向栈顶的指针
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
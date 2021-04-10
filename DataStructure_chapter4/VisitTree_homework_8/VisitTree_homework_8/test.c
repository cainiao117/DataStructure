#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

void visit(PT p);

int main()
{
	return 0;
}

int PreOrder(PT T)
{
	int count = 0;
	PT p = T;
	PT arr[MAXSIZE];//该数组是栈
	int top = -1;
	while ((p != NULL) || (top != -1))
	{
		while (p != NULL)
		{
			top++;
			arr[top] = p;
			p = p->lchild;
		}

		if ((arr[top]->lchild != NULL) && (arr[top]->rchild != NULL))
		{
			count++;
		}

		top--;
		p = p->rchild;

	}
	return count;
}
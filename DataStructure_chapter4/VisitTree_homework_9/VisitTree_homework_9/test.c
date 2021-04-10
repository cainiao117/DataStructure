//交换树的节点的所有左子树与右子树

#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

void Swap1(PT T);

int main()
{
	return 0;
}

void Swap1(PT T)
{
	if (T != NULL)
	{
		Swap1(T->lchild);
		Swap1(T->rchild);
		PT temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = T->lchild;
	}
}

void Swap2(PT T)
{
	PT arr[MAXSIZE];//该数组是栈
	int top = -1;//标记栈顶

	PT p = T;

	while ((p != NULL) || (top != -1))
	{
		while (p != NULL)
		{
			top++;
			arr[top] = p;

			PT temp = arr[top]->lchild;
			arr[top]->lchild = arr[top]->rchild;
			arr[top]->rchild = temp;

			p = p->lchild;
		}

		p = arr[top]->rchild;
		top--;
	}
}
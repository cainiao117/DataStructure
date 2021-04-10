//计算二叉树的高度
#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

int Height(PT T)
{
	int level = 0;
	PT arr[MAXSIZE];
	int front = 0;
	int rear = 0;
	int level = 0;
	int last = 0;

	PT p = T;
	arr[front] = p;
	int tag = 1;
	while (!(rear == front&&tag == 0))
	{
		if (arr[front]->lchild != NULL)
		{
			rear++;
			arr[rear] = arr[front]->lchild;
			tag++;
		}
		if (arr[front]->rchild != NULL)
		{
			rear++;
			arr[rear] = arr[front]->rchild;
			tag++;
		}

		if (front == last)
		{
			level++;
			last = rear;
		}

		front++;
		tag--;
	}
	return level;
}
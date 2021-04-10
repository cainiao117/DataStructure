#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 100

#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

bool Judge(PT T);

int main()
{
	return 0;
}

bool Judge(PT T)
{
	PT arr[MAXSIZE];
	int front = 0;
	int rear = 0;
	int count = 0;

	PT pre = T;
	arr[front] = T;
	rear++;
	count++;

	while (count)
	{
		if (arr[front])
		{
			arr[rear] = arr[front]->lchild;
			rear++;
			count++;
			arr[rear] = arr[front]->rchild;
			rear++;
			count++;
		}

		if (!pre)
		{
			return false;
		}
		pre = arr[front];
		front++;
		count--;

	}
	return true;
}
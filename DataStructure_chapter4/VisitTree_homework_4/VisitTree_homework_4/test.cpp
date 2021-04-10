//从下到上，从右到左层序遍历树：
#define _CRT_SECURE_NO_WARNINGS 1

#define LEN 6
#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;

void visit(PT p);

void LevelOrder(PT T)
{
	PT p = T;

	PT arr1[MAXSIZE];//初始化栈
	int top = -1;//栈指针
    
	PT arr2[LEN];//初始化队列
	int front = 0;
	int rear = 0;
	int tag = 0;//空标志

	arr2[rear] = p;
	rear = (rear + 1) % LEN;

	while (!(front==rear&&tag==0))
	{
		PT t = arr2[front];
		
		top++;
		arr1[top] = t;

		front = (front + 1) % LEN;
		if (t->lchild != NULL)
		{
			arr2[rear] = t->lchild;
			rear = (rear + 1) % LEN;
		}
		if (t->rchild != NULL)
		{
			arr2[rear] = t->rchild;
			rear = (rear + 1) % LEN;
		}
		   
	}

	while (top != -1)
	{
		visit(arr1[top]);
		top--;
	}
}
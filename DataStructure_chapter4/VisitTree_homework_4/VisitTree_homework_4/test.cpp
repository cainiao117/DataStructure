//���µ��ϣ����ҵ�������������
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

	PT arr1[MAXSIZE];//��ʼ��ջ
	int top = -1;//ջָ��
    
	PT arr2[LEN];//��ʼ������
	int front = 0;
	int rear = 0;
	int tag = 0;//�ձ�־

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
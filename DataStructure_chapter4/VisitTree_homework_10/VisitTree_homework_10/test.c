#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

typedef struct Stack{
	PT arr[MAXSIZE];
	int top;
}Stack;



int main()
{
	return 0;
}

ElemType PreOrder(PT T,unsigned int k){
	Stack S;//³õÊ¼Õ»
	S.top = -1;//±ê¼ÇÕ»¶¥

	unsigned int count = 0;

	PT p = T;
	while ((p != NULL) || (S.top != -1)){
		while (p != NULL){
			push(S, p);

			count++;
			if (count == k){
				return p->data;
			}

			p = p->lchild;
		}

		pop(S, p);
		p = p->rchild;
	}
}

void push(Stack S, PT p){
	if (S.top != MAXSIZE - 1){
		S.arr[++S.top] = p;
	}
}

void pop(Stack S, PT p)
{
	if (S.top != -1){
		p = S.arr[S.top--];
	}
}
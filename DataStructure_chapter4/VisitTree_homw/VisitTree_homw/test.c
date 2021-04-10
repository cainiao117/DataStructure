//删除所有值为x的根节点的子树
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

void PreOrder(PT p, ElemType x);
void push(Stack S, PT p);
void pop(Stack S, PT p);

int main()
{
	return 0;
}

void PreOrder(PT p,ElemType x)
{
	if (p != NULL){
		if (p->data == x){
			Free(p);
			return;
		}
		PreOrder(p->lchild,x);
		PreOrder(p->rchild,x);
	}
}


void Free(PT T){
	if (T != NULL){
		PT temp = T;
		free(T);
		T = NULL;
		Free(temp->lchild);
		Free(temp->rchild);
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
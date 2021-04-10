#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;

bool Judge(PT T);

bool result;
int main(){

	return 0; 
}

bool Judge1(PT T){
	PT arr[MAXSIZE];//规定栈
	int top = -1;//标记栈顶

	PT p = T;
	while (p != NULL || top != -1){
		while (p){
			arr[++top] = p;
			p = p->lchild;
		}
		if (arr[top]->lchild->data>arr[top]->data||arr[top]->rchild->data<arr[top]->data){
			return false;
		}
		top--;
		p = p->rchild;
	}
	return true;
}

void Judge2(PT T){
	if (T){
		Judge2(T->lchild);
		if (T->lchild->data>T->data || T->rchild->data<T->data){
			result=false;
		}
		Judge2(T->rchild);
	}
}

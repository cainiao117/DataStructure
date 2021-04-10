#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

ElemType FindMin(PT T);

int main(){
	return 0;
}

ElemType FindMin(PT T){
	while (T){
		if (!T->lchild){
			return T->data;
		}
		T = T->lchild;
	}
}

ElemType FindMax(PT T){
	while (T){
		if (!T->rchild){
			return T->data;
		}
		T = T->rchild;
	}
}
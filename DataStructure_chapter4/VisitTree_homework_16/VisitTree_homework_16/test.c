#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;


int main(){
	
	return 0;
}

PT p ;
PT pre ;

void InOrder(PT T){
	if (T){
		InOrder(T->lchild);
		if ((T->lchild == NULL) && (T->rchild == NULL)){
			pre->rchild = T;
			pre = T;
		}
		InOrder(T->rchild);
	}
}
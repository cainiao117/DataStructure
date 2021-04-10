#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
	unsigned int count;
}TNode, *PT;

unsigned int count = 0;

int main(){
	return 0;
}


PT LocateK(PT T,unsigned int k){
	if (T->lchild == NULL){
		if (k == 1){
			return T;
		}
		else{
			return LocateK(T->rchild, k-1);
		}
	}
	else{
		if (T->lchild->count == k - 1){
			return T;
		}
		else if(T->lchild->count>k-1){
			return LocateK(T->lchild, k);
		}
		else{
			return LocateK(T->rchild, k - (T->lchild->count) - 1);
		}
	}
}

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

int main(){

	return 0;
}

int Cal(PT T,ElemType x){
	unsigned int num = 0;
	if (!T){
		return 0;
	}
	else{
		while (T->data != x&&T!=NULL){
			if (T->data > x){
				T = T->lchild;
				num++;
			}
			else{
				T = T->rchild;
				num++;
			}
		}
	}
	return num;
}
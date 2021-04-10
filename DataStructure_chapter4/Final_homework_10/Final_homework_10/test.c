#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100

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

void Locate(PT T, ElemType k){
	PT arr[MAXSIZE];//Õ»
	int top = -1;//Õ»¶¥
	while (T){
		arr[++top] = T;
		T = T->rchild;
	}

	if (arr[top]->data >= k){
		printf("%d\n", arr[top]->data);
	}
	else{
		return;
	}
	top--;
	T = T->lchild;

}
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
	PT arr[MAXSIZE];//ջ
	int top = -1;//ջ��
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
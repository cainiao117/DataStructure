#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;

int main(){
	return 0;
}

bool judge(PT T1, PT T2){
	if (T1 == NULL&&T2 == NULL){
		return true;
	}
	else if(T1==NULL||T2==NULL){
		return false;
	}
	else{
		return judge(T1->lchild, T2->lchild) && judge(T1->rchild, T2->rchild);
	}
}
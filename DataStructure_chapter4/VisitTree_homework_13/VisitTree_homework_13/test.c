#define _CRT_SECURE_NO_WARNINGS 1
#define  MAXSIZE 100
#include <stdio.h>

typedef int ElemType;
typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode, *PT;

typedef struct Node{
	PT ptr;
	int tag;
}Node;

void ANCESTOR(PT ROOT, PT p, PT q, PT r);

int main()
{
	return 0;
}

void ANCESTOR(PT ROOT, PT p, PT q ){

	Node arr[MAXSIZE];//��ʼջ,��ű��������е�ָ��
	int top = -1;//���ջ��

	PT arr1[MAXSIZE];//����ջ��������Ƚڵ�
	int top1 = -1;

	PT arr2[MAXSIZE];//����ջ��������Ƚڵ�
	int top2 = -1;

	PT t = ROOT;
	while (t != NULL || top != -1){
		while (t != NULL){
			top++;
			arr[top].ptr = t;
			arr[top].tag = 0;
			t = t->lchild;
		}

		if (arr[top].ptr == p){
			for (int n = top; n >= 0; n--){
				arr1[++top1] = arr[n].ptr;
			}
		}

		if (arr[top].ptr == q){
			for (int n = top; n >= 0; n--){
				arr2[++top2] = arr[n].ptr;
			}
		}

		while (arr[top].tag == 1 && top > -1){
			top--;
		}

		if (top > -1){
			arr[top].tag = 1;
			t = arr[top].ptr->rchild;
		}
	}

	while (arr1[top1] == arr2[top2]){
		top1--;
		top2--;
	}

	return  arr1[++top1];
}
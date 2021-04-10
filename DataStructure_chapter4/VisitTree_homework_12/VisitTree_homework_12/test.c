//二叉树中，打印值为x所有祖先
#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100

#include <stdio.h>

typedef int ElemType;
typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;

typedef struct Node{
	PT ptr;
	int tag;
}Node;

int main()
{
	return 0;
}

void PostOrder(PT T,ElemType x){
	Node arr[MAXSIZE];//该数组为栈;
	int top = -1;

	PT p = T;
	while ((p != NULL) || (top != -1))
	{
		while (p != NULL){
			top++;
			arr[top].ptr = p;
			arr[top].tag = 1;
		}

		if (arr[top].ptr->data == x){
			while (top >= -1){
				top--;
				printf("%d\n", arr[top].ptr->data);
			}
			return;
		}

		while (arr[top].tag == 2&&top!=-1){
			top--;
		}
		
		if (top != -1){
			arr[top].tag = 2;
			p = arr[top].ptr->rchild;
		}
	}

}
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*PNode;

PNode LinkList(void);
int Show(PNode L);
void Free(PNode L);
void Print(PNode L);
void Print2(PNode p);

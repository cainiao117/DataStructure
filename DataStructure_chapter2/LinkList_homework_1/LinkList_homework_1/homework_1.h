#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*PNode;

PNode LinkList_TailInsert(void);
int Show(PNode L);
int Free(PNode L);
void Delete_x(PNode L, ElemType x);
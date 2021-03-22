#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*PNode;

PNode LinkList_TailInsert(void);
void Show(PNode L);
void Free(PNode L);
PNode Get_Min(PNode L);
void Delete(PNode L);
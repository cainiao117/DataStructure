#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* prior;
	struct LNode* next;
}LNode,*PNode;


PNode LinkListTailInsert(void);
bool Show(PNode L);
bool Free(PNode L);

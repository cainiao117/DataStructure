#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
	struct LNode* prior;
	unsigned int freq;
}LNode,*PNode;


PNode LinkListTailInsert(void);
bool Show(PNode L);
bool Free(PNode L);
PNode Locate(PNode L, ElemType e);
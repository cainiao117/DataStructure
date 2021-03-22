#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*PNode;


PNode LinkListTailInsert(void);
bool Show(PNode L);
bool Free(PNode L);
PNode FindTail(PNode L);
void Inverse(PNode L,PNode T);
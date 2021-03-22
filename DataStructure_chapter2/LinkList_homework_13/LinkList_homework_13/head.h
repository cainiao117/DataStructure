#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode, *PNode;

PNode LinkListTailInsert(void);
bool Show(PNode L);
bool Free(PNode L);
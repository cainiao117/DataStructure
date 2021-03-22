#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode;

void LinkList_headInsert(LNode* L);
void LinkList_tailInsert(LNode* r);
void LinkList_Free(LNode* L);
void LinkList_show(LNode* L);

int main()
{
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList_tailInsert(L);
	LinkList_show(L);
	LinkList_Free(L);
	return 0;
}

void LinkList_headInsert(LNode* L)
{
	ElemType x;
	printf("please enter an Element:");
	scanf("%d", &x);
	while (x != 9999)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		printf("please enter another Element:");
		scanf("%d", &x);
	}	
}

void LinkList_tailInsert(LNode* r)
{
	ElemType x;
	printf("please enter an Element:");
	scanf("%d", &x);
	while (x != 9999)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		printf("please enter another Element:");
		scanf("%d", &x);
	}
	r->next = NULL;
}

void LinkList_Free(LNode* L)
{
	while (L->next != NULL)
	{
		LNode* temp = L->next;
		free(L);
		L = temp;
	}
}

void LinkList_show(LNode* L)
{
	printf("%d ",L->next->data);
	L = L->next->next;
	do
	{
		printf("%d ", L->data);
		L = L->next;
	} while (L != NULL);
}

LNode* GetElem(LNode* L, int i)
{
	int count = 1;
	LNode* p = L->next;
	if (i < 0)
	{
		return NULL;
	}
	if (i = 0)
	{
		return L;
	}
	while ((count < i) && (p!= NULL))
	{
		p = p->next;
		count++;
	}
	return p;
}

LNode* LocateELem(LNode* L, ElemType e)
{
	LNode* p = L->next;
	while (p->data != e&&p!=NULL)
	{
		p = p->next;
	}
	return p;
}


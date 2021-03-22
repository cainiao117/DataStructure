#define _CRT_SECURE_NO_WARNINGS 1

#include "homework_5.h"

PNode LinkListTailInsert(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));
	PNode T = L;
	ElemType e;
	int len;
	printf("please enter the number of element:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		printf("please enter the element(%d):", i + 1);
		scanf("%d", &e);
		PNode p = (PNode)malloc(sizeof(LNode));
		p->data = e;
		T->next = p;
		T = p;
	}
	T->next = NULL;
	return L;
}

bool Show(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		printf("Empty!\n");
		return false;
	}
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return true;
}

bool Free(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		free(L);
		return false;
	}
	while (p != NULL)
	{
		PNode temp = p->next;
		free(p);
		p = temp;
	}
	return true;
}

PNode FindTail(PNode L)
{
	PNode p = L->next;
	PNode T = NULL;
	if (p == NULL)
	{
		printf("Empty!\n");
		return NULL;
	}
	while (p != NULL)
	{
		T = p;
		p = p->next;
	}
	return T;
}

void Inverse(PNode L, PNode T)
{
	PNode p = L->next;
	L->next = T;
	while (p != T)
	{
		PNode temp_1 = p->next;
		p->next = T->next;
		T->next = p;
		p = temp_1;
	}
}
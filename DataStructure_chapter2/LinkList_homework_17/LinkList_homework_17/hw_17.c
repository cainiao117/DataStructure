#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

PNode LinkListTailInsert(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));
	PNode T = L;
	int len;
	printf("please enter the number of element:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		ElemType e;
		printf("please enter the number(%d):", i + 1);
		scanf("%d", &e);
		PNode p = (PNode)malloc(sizeof(LNode));
		p->data = e;
		PNode temp = T->next;
		T->next = p;
		p->next = temp;
		p->prior = T;
		T = p;
	}
	T->next = L;
	L->prior = T;
	return L;
}

bool Show(PNode L)
{
	PNode p = L->next;
	if (p == L)
	{
		printf("Empty!!!\n");
		return false;
	}
	while (p != L)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return true;
}

bool Free(PNode L)
{
	PNode p = L->next;
	if (p == L)
	{
		printf("Empty!!!\n");
		return false;
	}
	while (p != L)
	{
		PNode temp = p->next;
		free(p);
		p = temp;
	}
	return true;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

PNode LinkListTailInsert(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));
	L->next = NULL;
	PNode T = L;
	int len;
	printf("please enter the number of element:");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		ElemType e;
		printf("please enter the element(%d):", i + 1);
		scanf("%d", &e);
		PNode p = (PNode)malloc(sizeof(LNode));
		p->data = e;
		p->next = T->next;
		T->next = p;
		p->prior = T;
		p->freq = 0;
		T = p;
	}
	L->prior = T;
	T->next = L;
	return L;
}

bool Show(PNode L)
{
	PNode p = L->next;
	if (p == L)
	{
		printf("Nothing!\n");
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
		printf("Nothing!\n");
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

PNode Locate(PNode L, ElemType e)
{
	PNode p = L->next;
	if (p == L)
	{
		printf("Nothing!!!\n");
		return NULL;
	}

	PNode target = p;

	bool flag = false;
	while (p != L)
	{
		if (p->data == e)
		{
			flag = true;
			target = p;
			target->freq += 1;
			break;
		}
		p = p->next;
	}

	if (flag)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没有该元素\n");
	}

	target->prior->next = target->next;
	target->next->prior = target->prior;

	PNode toward = target->prior;
	while (toward != L)
	{
		if (toward->freq > target->freq)
		{
			break;
		}
		toward = toward->prior;
	}

	target->next = toward->next;
	target->prior = toward;
	toward->next->prior = target;
	toward->next = target;

	return target;
}
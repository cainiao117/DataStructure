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
		printf("Empty!!!\n");
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
		printf("Nothing!!!\n");
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

//unsigned int Len(PNode L)
//{
//	int count = 0;
//	PNode p = L->next;
//	if (p == NULL)
//	{
//		return 0;
//	}
//	while (p != NULL)
//	{
//		count++;
//		p = p->next;
//	}
//	return count;
//}

bool dc(PNode L, int num)
{
	PNode p = L->next;
	int arr[20] = { 0 };
	int top = -1;
	for (int i = 0; i < num / 2; i++)
	{
		top++;
		arr[top] = p->data;
		p = p->next;
	}

	for (int i = 0; i < num / 2; i++)
	{
		printf("%d ", arr[i]);
	}

	if (num / 2)
	{
		p = p->next;
	}

	while (p != NULL)
	{
		if (p->data != arr[top])
		{
			return false;
		}
		top--;
		p = p->next;
	}

	return true;
}
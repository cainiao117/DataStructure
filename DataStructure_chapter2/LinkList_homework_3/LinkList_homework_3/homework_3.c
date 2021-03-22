#define _CRT_SECURE_NO_WARNINGS 1
#include "homework_3.h"

PNode LinkList(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));
	PNode T = L;//T为尾指针
	ElemType e;
	int len;
	printf("请输入链表的元素个数：");
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个元素：", i+1);
		scanf("%d", &e);
		PNode s = (PNode)malloc(sizeof(LNode));
		s->data = e;
		T->next = s;
		T = s;
	}
	T->next = NULL;
	return L;
}

int Show(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		printf("Nothing!\n");
		return -1;
	}
	do
	{
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
	return 0;
}

void Free(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		return;
	}
	while (p != NULL)
	{
		PNode temp = p->next;
		free(p);
		p = temp;
	}
	L->next = NULL;
}

void Print(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		printf("Nothing!\n");
	}
	int arr[50];
	int count = 0;
	while (p != NULL)
	{
		arr[count] = p->data;
		p = p->next;
		count++;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
}

void Print2(PNode p)
{
	if (p->next != NULL)
	{
		Print2(p->next);
	}
	printf("%d ", p->data);
}
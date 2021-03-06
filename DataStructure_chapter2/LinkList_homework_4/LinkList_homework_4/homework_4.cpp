#define _CRT_SECURE_NO_WARNINGS 1
#include "homework_4.h"

PNode LinkList_TailInsert(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));//L是头指针
	PNode T = L;//T是尾指针
	int len;
	printf("请输入输入元素的个数：");
	scanf("%d", &len);
	ElemType e;
	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个元素：", i);
		scanf("%d", &e);
		PNode s = (PNode)malloc(sizeof(LNode));
		s->data = e;
		T->next = s;
		T = s;
	}
	return L;
}

void Show(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		printf("Nothing!\n");
	}
	do
	{
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}

void Free(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		printf("Nothing!\n");
	}
	while (p != NULL)
	{
		PNode temp = p->next;
		free(p);
		p = temp;
	}
	L->next = NULL;
}


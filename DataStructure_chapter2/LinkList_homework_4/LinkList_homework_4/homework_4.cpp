#define _CRT_SECURE_NO_WARNINGS 1
#include "homework_4.h"

PNode LinkList_TailInsert(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));//L��ͷָ��
	PNode T = L;//T��βָ��
	int len;
	printf("����������Ԫ�صĸ�����");
	scanf("%d", &len);
	ElemType e;
	for (int i = 0; i < len; i++)
	{
		printf("�������%d��Ԫ�أ�", i);
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


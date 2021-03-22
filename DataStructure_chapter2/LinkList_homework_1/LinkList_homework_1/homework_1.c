#define _CRT_SECURE_NO_WARNINGS 1

#include "homework_1.h"

PNode LinkList_TailInsert(void)
{
	PNode L = (PNode)malloc(sizeof(LNode));
	PNode T = L;//T��βָ�룻
	int len;//�����е�Ԫ�ظ�����
	printf("����������Ԫ�ظ�����");
	scanf("%d", &len);
	ElemType e;//�����Ԫ��
	for (int i = 0; i < len; i++)
	{
		printf("�������%d��Ԫ��:", i + 1);
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
	PNode p = L->next;//pָ��ָ���һ��Ԫ��;
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

int Free(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
	{
		printf("Nothing!\n");
		return -1;
	}
	PNode temp;
	do
	{
		temp = p->next;
		free(p);
		p = temp;
	} while (p != NULL);
	L->next = NULL;
	return 0;
}

void Delete_x(PNode L, ElemType x)
{
	PNode pre_p = L;
	PNode p = L->next;//pָ���һ��Ԫ��;
	while (p != NULL)
	{
		if (p->data == x)
		{
			PNode temp = p->next;
			pre_p->next = temp;
			free(p);
			p = temp;
		}
		else
		{
			pre_p = p;
			p = p->next;
		}
	}
}
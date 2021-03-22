#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int main()
{
	PNode L1 = LinkListTailInsert();
	PNode L2 = LinkListTailInsert();
	Show(L1);
	printf("\n");
	Show(L2);
	printf("\n");

	PNode p1 = L1->next;
	L1->next = NULL;
	PNode T = L1;
	PNode p2 = L2->next;
	while (p1&&p2)
	{
		if ((p1->data) < (p2->data))
		{
			PNode temp = p1->next;
			free(p1);
			p1 = temp;
		}
		else if ((p1->data)>(p2->data))
		{
			PNode temp = p2->next;
			free(p2);
			p2=temp;
		}
		else
		{
			PNode p = (PNode)malloc(sizeof(LNode));
			p->data = p1->data;
			T->next = p;
			T = p;

			PNode temp1 = p1->next;
			free(p1);
			p1 = temp1;

			PNode temp2 = p2->next;
			free(p2);
			p2 = temp2;
		}
	}

	while (p1 != NULL)
	{
		PNode temp = p1->next;
		free(p1);
		p1 = temp;
	}

	while (p2 != NULL)
	{
		PNode temp = p2->next;
		free(p2);
		p2 = temp;
	}

	T->next = NULL;

	Show(L1);
	printf("\n");
	Show(L2);
	printf("\n");

	Free(L1);
	L1 = NULL;
	Free(L2);
	L2 = NULL;
	return 0;
}
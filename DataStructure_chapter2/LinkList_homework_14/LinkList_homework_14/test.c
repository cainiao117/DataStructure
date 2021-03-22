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

	PNode L3 = (PNode)malloc(sizeof(LNode));
	L3->next = NULL;
	PNode T = L3;
	PNode p1 = L1->next;
	PNode p2 = L2->next;
	while (p1&&p2)
	{
		if ((p1->data) < (p2->data))
		{
			p1 = p1->next;
		}
		else if ((p1->data) > (p2->data))
		{
			p2 = p2->next;
		}
		else
		{
			PNode p = (PNode)malloc(sizeof(LNode));
			p->data = p1->data;
			T->next = p;
			T = p;

			p1 = p1->next;
			p2 = p2->next;
		}
	}
	T->next = NULL;

	Show(L3);
	printf("\n");

	Free(L1);
	L1 = NULL;
	Free(L2);
	L2 = NULL;
	Free(L3);
	L3 = NULL;
	return 0;
}
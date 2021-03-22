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
	PNode p2 = L2->next;
	L1->next = NULL;
	while ((p1 != NULL) && (p2 != NULL))
	{
		if ((p1->data) <= (p2->data))
		{
			PNode temp = p1->next;
			PNode temp1 = L1->next;
			L1->next = p1;
			p1->next = temp1;
			p1 = temp;
		}
		else
		{
			PNode temp = p2->next;
			PNode temp1 = L1->next;
			L1->next = p2;
			p2->next = temp1;
			p2 = temp;
		}
	}
	while (p1 != NULL)
	{
		PNode temp = L1->next;
		PNode temp1 = p1->next;
		L1->next = p1;
		p1->next = temp;
		p1 = temp1;
	}
	while (p2 != NULL)
	{
		PNode temp = L1->next;
		PNode temp1 = p2->next;
		L1->next = p2;
		p2->next = temp;
		p2 = temp1;
	}

	Show(L1);
	Free(L1);
	Free(L2);
	return 0;
}
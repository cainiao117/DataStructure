#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	PNode T1 = L;
	Show(L);
	printf("\n");

	PNode L2 = (PNode)malloc(sizeof(LNode));
	PNode T2 = L2;
	int count = 0;
	PNode p = L->next;
	while (p != NULL)
	{
		count++;
		if (count % 2)
		{
			T1->next = p;
			T1 = p;
		}
		else
		{
			T2->next = p;
			T2 = p;
		}
		p = p->next;
	}
	T1->next = NULL;
	T2->next = NULL;

	Show(L);
	printf("\n");
	Show(L2);
	printf("\n");

	Free(L);
	Free(L2);
	L = NULL;
	return 0;
}
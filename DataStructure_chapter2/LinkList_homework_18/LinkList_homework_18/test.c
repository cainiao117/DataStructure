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

	PNode T1 = L1->next;
	while (T1->next != L1)
	{
		T1 = T1->next;
	}

	PNode T2 = L2->next;
	while (T2->next != L2)
	{
		T2 = T2->next;
	}

	T1->next = L2->next;
	T2->next = L1;

	Show(L1);
	Free(L1);
	return 0;
}
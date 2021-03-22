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

	PNode p1 =L1->next;
	PNode signal = p1;
	PNode p2 = L2->next;
	while (p1&&p2)
	{
		if (p1->data == p2->data)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			signal = signal->next;
			p1 = signal;
			p2 = L2->next;
		}
	}

	if (!p2)
	{
		printf("B in A\n");
	}
	else
	{
		printf("Not\n");
	}

	Free(L1);
	L1 = NULL;
	Free(L2);
	L2 = NULL;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	Show(L);
	printf("\n");
	
	PNode p = L->next;
	while (p != NULL)
	{
		PNode pre =p;
		PNode p2 = p->next;
		while (p2 != NULL)
		{
			if (p2->data == p->data)
			{
				PNode temp = p2->next;
				pre->next = temp;
				free(p2);
				p2 = temp;
			}
			else
			{
				pre = p2;
				p2 = p2->next;
			}
		}
		p = p->next;
	}

	Show(L);

	Free(L);
	L = NULL;
	return 0;
}
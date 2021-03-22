#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	Show(L);
	printf("\n");
	
	while (L->next!= NULL)
	{
		PNode p = L->next;
		PNode pre_p = L;
		PNode min_p = pre_p;
		ElemType min = p->data;
		while (p != NULL)
		{
			if (p->data < min)
			{
				min = p->data;
				min_p = pre_p;
			}
			pre_p = p;
			p = p->next;
		}

		printf("%d\n", min_p->next->data);
		
		PNode temp = min_p->next;
		min_p->next = min_p->next->next;
		free(temp);
	}

	Free(L);
	L = NULL;
	return 0;
}
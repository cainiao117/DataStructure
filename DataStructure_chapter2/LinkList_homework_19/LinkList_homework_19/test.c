#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	Show(L);
	printf("\n");

	/*PNode signal = L->next;
	while (signal != L)
	{
		ElemType min = signal->data;
		PNode p=signal->next;
		PNode pre_p=signal;
		PNode min_p=pre_p;
		while (p != L)
		{
			if (p->data < min)
			{
				min = p->data;
				min_p = pre_p;
			}
			pre_p = p;
			p = p->next;
		}
		PNode temp = min_p->next->next;
		printf("%d ", min_p->next->data);
		free(min_p->next);
		min_p->next = temp;

		signal = L->next;

	}*/

	PNode p, pre, minp, minpre;
	while (L->next != L)
	{
		p = L->next;
		pre = L;
		minp = p;
		minpre = pre;
		while (p != L)
		{
			if (p->data < minp->data)
			{
				minp = p;
				minpre = pre;
			}
			pre = p;
			p = p->next;
		}
		printf("%d ", minp->data);
		minpre->next = minp->next;
		free(minp);
	}

	Free(L);
	L = NULL;
	return 0;
}
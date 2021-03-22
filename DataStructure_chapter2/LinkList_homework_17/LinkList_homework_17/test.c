#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	Show(L);

	PNode q = L->next;
	PNode p = L->prior;
	bool flag = true;
	while ((q!=p->prior)&&(q!=p))
	{
		if (q->data != p->data)
		{
			flag = false;
			break;
		}
		q = q->next;
		p = p->prior;
	}
	if (flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	Free(L);
	L = NULL;
	return 0;
}
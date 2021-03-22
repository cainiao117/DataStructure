#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	Show(L);
	/*printf("%d ", L->next->data);*/
	Locate(L, 3);

	Free(L);
	return 0;
}
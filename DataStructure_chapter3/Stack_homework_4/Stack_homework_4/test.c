#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

int main()
{
	PNode L = LinkListTailInsert();
	Show(L);

	if (dc(L,5))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	Free(L);
	L = NULL;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include "homework_3.h"

int main()
{
	PNode L = LinkList();
	Show(L);
	printf("\n");
	Print(L);
	printf("\n");
	PNode p = L->next;
	Print2(p);
	Free(L);
	return 0;
}
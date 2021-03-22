#define _CRT_SECURE_NO_WARNINGS 1
#include "homework_5.h"

int main()
{
	PNode L=LinkListTailInsert();
	Show(L);
	printf("\n");
	PNode T = FindTail(L);
	printf("%d\n", T->data);
	Inverse(L, T);
	Show(L);
	Free(L);
	L = NULL;
	return 0;
}
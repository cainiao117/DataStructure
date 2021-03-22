#define _CRT_SECURE_NO_WARNINGS 1

#include "homework_4.h"

int main()
{
	PNode L=LinkList_TailInsert();
	printf("%d\n", L->next->data);
	PNode p_min = Get_Min(L);
	Show(L);
	printf("%d\n", p_min);
	/*Delete(p_min);*/
	Show(L);
	Free(L);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "homework_6.h"

int main()
{
	
	PNode L = LinkListTailInsert();
	Show(L);
	const int len=Len(L);
	printf("len=%d\n", len);
	PNode arr[100];
	PNode p = L->next;
	for (int i = 0; i < len; i++)
	{
		arr[i] = p;
		p = p->next;
	}
	
	//bubble_sort
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if ((arr[j]->data)>(arr[j + 1]->data))
			{
				PNode temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	/*for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]->data);
	}*/
	PNode T = L;
	for (int i = 0; i < len; i++)
	{
		T->next = arr[i];
		T = arr[i];
	}
	T->next = NULL;

	Show(L);
	Free(L);
	L = NULL;
	return 0;
}
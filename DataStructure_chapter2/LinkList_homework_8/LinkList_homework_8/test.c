#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

int main()
{
	PNode L1 = LinkListTailInsert();
	PNode L2 = LinkListTailInsert();
	Show(L1);
	printf("\n");
	Show(L2);
	printf("\n");

	PNode p1 = L1->next;
	int len1 = Len(L1);
	PNode arr1[100];
	for (int i = 0; i < len1; i++)
	{
		arr1[i] = p1;
		p1 = p1->next;
	}

	PNode p2 = L2->next;
	int len2 = Len(L2);
	PNode arr2[100];
	for (int i = 0; i < len2; i++)
	{
		arr2[i] = p2;
		p2 = p2->next;
	}

	for (int i = 0; i < len1; i++)
	{
		bool flag = false;
		for (int j = 0; j < len2; j++)
		{
			if (arr2[j] == arr1[i])
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			printf("%d ", arr1[i]->data);
		}
	}

	Free(L1);
	L1 = NULL;
	Free(L2);
	L2 = NULL;
	return 0;
}
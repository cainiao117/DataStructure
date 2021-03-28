#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

bool Push(SqStack s, int n, ElemType e)
{
	if (s.top1 == s.top2)
	{
		printf("Õ»Âú\n");
		return false;
	}

	if (n == 1)
	{
		s.data[++s.top1] = e;
	}
	else
	{
		s.data[--s.top2] = e;
	}

	return true;
}

bool Pop(SqStack s, int n)
{
	if (n == 1)
	{
		if (s.top1 == -1)
		{
			return false;
		}
		else
		{
			s.top1--;
			return true;
		}
	}
	else
	{
		if (s.top2 == MAXSIZE)
		{
			return false;
		}
		else
		{
			s.top2++;
			return true;
		}
	}
}
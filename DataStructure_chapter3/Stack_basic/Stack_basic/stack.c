#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

PSqStack InitStack(void)
{
	PSqStack L = (PSqStack)malloc(sizeof(SqStack));
	L->top = -1;
	return L;
}

bool StackEmpty(PSqStack L)
{
	if (L->top == -1)
	{
		return true;
	}
	return false;
}

bool Push(PSqStack L, ElemType e)
{
	if (L->top == MAXSIZE - 1)
	{
		return false;
	}
	L->data[++L->top] = e;
	return true;
}

bool Pop(PSqStack L,ElemType* p)
{
	if (L->top == -1)
	{
		return false;
	}
	*p = L->data[(L->top)--];
	return true;
}


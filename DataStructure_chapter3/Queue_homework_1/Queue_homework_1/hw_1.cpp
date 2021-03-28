#define _CRT_SECURE_NO_WARNINGS 1
#include "head.h"

bool EnQueue(Queue &Q, ElemType x)
{
	if ((Q.front == Q.rear) && (Q.tag == 1))
	{
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.tag = 1;
	return true;
}

bool DeQueue(Queue &Q)
{
	if ((Q.front == Q.rear) && (Q.tag == 0))
	{
		return false;
	}
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.tag = 0;
	return true;
}
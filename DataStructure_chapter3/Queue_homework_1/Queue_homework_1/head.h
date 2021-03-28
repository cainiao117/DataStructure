#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 6

typedef int ElemType;

typedef struct Queue{
	ElemType data[MAXSIZE];
	int front;
	int rear;
	int tag;
}Queue;

bool EnQueue(Queue &Q, ElemType x);
bool DeQueue(Queue &Q);
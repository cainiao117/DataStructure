#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 50

typedef int ElemType;

typedef struct SqStack{
	ElemType data[MAXSIZE];
	int top1 ;
	int top2 ;
}SqStack;
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool Juage(char* p);

int main()
{

	char arr[10];
	scanf("%s", arr);
	printf("%s\n", arr);
	if (Juage(arr))
	{
		printf("合法\n");
	}
	else
	{
		printf("不合法\n");
	}

	return 0;
}

bool Juage(char* p)
{
	char Stack[20];
	int top = -1;
	int len = strlen(p);
	for (int i = 0; i < len; i++)
	{
		switch (*(p + i))
		{
		case '(':
		case '[':
		case '{':
			Stack[++top] = *(p + i);
			break;
		case ')':
			if (Stack[top] == '(')
			{
				top--;
			}
			else
			{
				return false;
			}
		case ']':
			if (Stack[top] == ']')
			{
				top--;
			}
			else
			{
				return false;
			}
		case '}':
			if (Stack[top] == '{')
			{
				top--;
			}
			else
			{
				return false;
			}
		}
	}

	if (-1 == top)
	{
		return true;
	}
	else
	{
		return false;
	}
}
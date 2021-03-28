#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

bool Judge(char* p, int len);

int main()
{
	/*char arr[8] = { 'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O' };*/
	/*char arr[8] = { 'I', 'I', 'I', 'O', 'I', 'O', 'I', 'O' };*/
	char arr[8] = { 'I', 'I', 'I', 'O', 'O', 'I', 'O', 'O' };
	if (Judge(arr,8) == true)
	{
		printf("�Ϸ�\n");
	}
	else
	{
		printf("���Ϸ�\n");
	}
	return 0;
}

bool Judge(char* p, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (*(p + i) == 'I')
		{
			sum++;
		}
		else if (*(p + i) == 'O')
		{
			sum--;
		}
		else
		{
			printf("��%d��Ԫ�ز��Ϸ�\n", i + 1);
		}

		if (sum < 0)
		{
			return false;
		}
	}
	if (sum == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}
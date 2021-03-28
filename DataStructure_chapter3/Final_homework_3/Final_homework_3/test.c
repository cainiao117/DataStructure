#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define Maxsize 10		//栈的最大容量，此时n能取的最大值为11

double fun(int n, double x);  //函数声明

int main(){
	int n = 0;
	double x = 0;
	printf("输入n:", n);
	scanf_s("%d", &n);
	if (n < 0){
		printf("n不能为负数");
		while (1);  //避免窗口一闪而过
		exit(0);
	}
	printf("输入x:", x);
	scanf_s("%lf", &x);

	printf("计算结果为%lf", fun(n, x));
	while (1);
	return 0;
}

//使用栈实现递归操作
double fun(int n, double x){
	if (n == 0)	return 1;
	struct stack{		//定义栈
		int no;			//n
		double val;		//pn(x)
	}st[Maxsize];

	double fv0 = 1, fv1 = 2 * x;		//边界
	int top = -1;					//初始栈顶
	for (int i = n; i >= 2; i--){	//将n存入栈
		top++;
		st[top].no = i;
	}
	while (top >= 0){			//将Pn(x)存入栈
		st[top].val = 2 * x*fv1 - 2 * (st[top].no - 1)*fv0;
		fv0 = fv1;				//迭代
		fv1 = st[top].val;		//迭代，当top=0时，此时no为n，val所存的值即为最终结果
		top--;
	}
	return fv1;
}

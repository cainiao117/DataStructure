#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define Maxsize 10		//ջ�������������ʱn��ȡ�����ֵΪ11

double fun(int n, double x);  //��������

int main(){
	int n = 0;
	double x = 0;
	printf("����n:", n);
	scanf_s("%d", &n);
	if (n < 0){
		printf("n����Ϊ����");
		while (1);  //���ⴰ��һ������
		exit(0);
	}
	printf("����x:", x);
	scanf_s("%lf", &x);

	printf("������Ϊ%lf", fun(n, x));
	while (1);
	return 0;
}

//ʹ��ջʵ�ֵݹ����
double fun(int n, double x){
	if (n == 0)	return 1;
	struct stack{		//����ջ
		int no;			//n
		double val;		//pn(x)
	}st[Maxsize];

	double fv0 = 1, fv1 = 2 * x;		//�߽�
	int top = -1;					//��ʼջ��
	for (int i = n; i >= 2; i--){	//��n����ջ
		top++;
		st[top].no = i;
	}
	while (top >= 0){			//��Pn(x)����ջ
		st[top].val = 2 * x*fv1 - 2 * (st[top].no - 1)*fv0;
		fv0 = fv1;				//����
		fv1 = st[top].val;		//��������top=0ʱ����ʱnoΪn��val�����ֵ��Ϊ���ս��
		top--;
	}
	return fv1;
}

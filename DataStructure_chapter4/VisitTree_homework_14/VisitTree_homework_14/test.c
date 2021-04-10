#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100

typedef int ElemType;
typedef struct TNode{
	ElemType data;
	struct TNode* lchild;
	struct TNode* rchild;
}TNode,*PT;

int main()
{
	return 0;
}

int CalWidth(PT T){
	PT arr[MAXSIZE];//��������������
	int front = -1;//ָ�����
	int rear = 0;//ָ���β
	unsigned int count = 0;//��Ƕ����Ƿ�Ϊ��
	unsigned int width = 0;//�����
	unsigned sum = 0;//��ÿ����
	int pre_last = rear;
	
	PT p = T;
	arr[++front] = p;
	count++;
	while (count){

		sum++;

		if (arr[front]->lchild){
			arr[++rear] = arr[front]->lchild;
			count++;
		}
		if (arr[front]->rchild){
			arr[++rear] = arr[front]->rchild;
			count++;
		}

		if (front == pre_last){
			pre_last = rear;
			if(sum>width){
				width = sum;
				sum = 0;
			}
		}

		front++;
		count--;
	}
	return width;
}
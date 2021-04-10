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
	PT arr[MAXSIZE];//该数组用作队列
	int front = -1;//指向队首
	int rear = 0;//指向队尾
	unsigned int count = 0;//标记队列是否为空
	unsigned int width = 0;//树宽度
	unsigned sum = 0;//树每层宽度
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
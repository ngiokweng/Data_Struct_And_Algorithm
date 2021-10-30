#include <iostream>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

#define MAXQSIZE 100

struct SqQueue {
	QElemType* base; //數組
	int front;  //頭指針
	int rear;   //尾指針
};

//初始化隊列
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//銷毀隊列
Status DestroyQueue(SqQueue& Q) {
	if (Q.base) {
		delete[] Q.base;
		Q.base = NULL;
	}
	return OK;
}

//清空隊列
Status ClearQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return OK;
}

//返回隊列長度
int QueueLength(SqQueue Q) {
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//入隊
Status EnQueue(SqQueue& Q,QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

//出隊
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

//取得隊頭元素
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear) {
		return Q.base[Q.front];
	}
}


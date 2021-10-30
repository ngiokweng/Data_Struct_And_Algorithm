#include <iostream>
using namespace std;

//��Ƶ��G���A�N�X
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
	QElemType* base; //�Ʋ�
	int front;  //�Y���w
	int rear;   //�����w
};

//��l�ƶ��C
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//�P�����C
Status DestroyQueue(SqQueue& Q) {
	if (Q.base) {
		delete[] Q.base;
		Q.base = NULL;
	}
	return OK;
}

//�M�Ŷ��C
Status ClearQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return OK;
}

//��^���C����
int QueueLength(SqQueue Q) {
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//�J��
Status EnQueue(SqQueue& Q,QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

//�X��
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

//���o���Y����
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear) {
		return Q.base[Q.front];
	}
}


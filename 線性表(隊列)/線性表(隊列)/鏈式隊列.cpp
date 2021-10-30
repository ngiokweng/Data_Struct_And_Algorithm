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

typedef struct QNode {	
	QElemType data;
	QNode* next;
}*QueuePtr;

struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
};

//��l�ƶ��C
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//�P�����C
Status DestroyQueue(LinkQueue& Q) {
	QNode* p = NULL;
	while (Q.front){
		p = Q.front->next;
		delete Q.front;
		Q.front = p;
		//�Ϊ̥i�H�ϥΤU�C��k�A�i�٤@�I�Ŷ��A�]�����Ωw�qp
		/*Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;*/
	}
	return OK;
}

//�J��
Status EnQueue(LinkQueue& Q,QElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

//�X��
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	QNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	delete p;
	return OK;
}

//���o�춤�C���Y����
Status GetHead(LinkQueue Q, QElemType& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.front->next->data;
	return OK;
}
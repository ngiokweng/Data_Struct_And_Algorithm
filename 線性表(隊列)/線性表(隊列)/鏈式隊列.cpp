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

typedef struct QNode {	
	QElemType data;
	QNode* next;
}*QueuePtr;

struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
};

//初始化隊列
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//銷毀隊列
Status DestroyQueue(LinkQueue& Q) {
	QNode* p = NULL;
	while (Q.front){
		p = Q.front->next;
		delete Q.front;
		Q.front = p;
		//或者可以使用下列方法，可省一點空間，因為不用定義p
		/*Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;*/
	}
	return OK;
}

//入隊
Status EnQueue(LinkQueue& Q,QElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

//出隊
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.front == Q.rear) return ERROR;
	QNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	delete p;
	return OK;
}

//取得鏈隊列的頭元素
Status GetHead(LinkQueue Q, QElemType& e) {
	if (Q.rear == Q.front)return ERROR;
	e = Q.front->next->data;
	return OK;
}
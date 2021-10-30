#include <iostream>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct StackNode {
	int data;
	StackNode* next;
}*LinkStack;

//初始化鏈棧
int InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}

int StackEmpty(LinkStack S) {
	if (S == NULL)return TRUE;
	return FALSE;
}

//入棧
int Push(LinkStack& S,int data) {
	StackNode* p = new StackNode;
	p->data = data;
	p->next = S;
	S = p;
	return OK;
}

//出棧
int Pop(LinkStack& S, int& data) {
	if (!S)return ERROR;
	StackNode* p = S;
	data = S->data;
	S = S->next;
	delete p;
	return OK;
}

//取最頂元素
int GetTop(LinkStack S) {
	if (S)return S->data;
	return ERROR;
}

int main() {
	return 0;
}
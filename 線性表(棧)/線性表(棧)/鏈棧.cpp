#include <iostream>
using namespace std;

//��Ƶ��G���A�N�X
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

//��l�����
int InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}

int StackEmpty(LinkStack S) {
	if (S == NULL)return TRUE;
	return FALSE;
}

//�J��
int Push(LinkStack& S,int data) {
	StackNode* p = new StackNode;
	p->data = data;
	p->next = S;
	S = p;
	return OK;
}

//�X��
int Pop(LinkStack& S, int& data) {
	if (!S)return ERROR;
	StackNode* p = S;
	data = S->data;
	S = S->next;
	delete p;
	return OK;
}

//���̳�����
int GetTop(LinkStack S) {
	if (S)return S->data;
	return ERROR;
}

int main() {
	return 0;
}
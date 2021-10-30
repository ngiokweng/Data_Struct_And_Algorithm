#include <iostream>
using namespace std;

//��Ƶ��G���A�N�X
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100

struct SqStack {
	int* top;	//���V�̳�
	int* base;  //���V�̩�
	int stacksize;  //�̪��̤j�e�q
};

//��l�ƴ�
int initStack(SqStack& S) {
	S.base = new int[MAXSIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//�P���̪��ާ@
int DestoryStack(SqStack S) {
	if (S.base) {
		delete[] S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;  //�]�m��NULL�O�]��delete�u�O���񤺦s�A��S.base�MS.top�̵M�O���V�@�Ӥ��s�a�}
	}
	return OK;
}

//�P�_�̬O�_����
int StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return FALSE;
}

//�D�̪�����
int StackLength(SqStack& S) {
	if (!S.base) return ERROR;
	return S.top - S.base;
}

//���o�̳�����
int GetTop(SqStack& S,int& e) {
	if (S.base == S.top) return ERROR;
	e = *(S.top - 1);
	return OK;
}

//�m�Ŵ�
int ClearStack(SqStack S) {
	if (S.base) S.top = S.base;
	return OK;
}

//�J��
int Push(SqStack& S, int e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
	return OK;
}

//�X��
int pop(SqStack& S, int& e) {
	if (S.top == S.base)return ERROR;
	e = *(--S.top);
	return OK;
}



int main() {
	return 0;
}
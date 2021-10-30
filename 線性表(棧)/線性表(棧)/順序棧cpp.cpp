#include <iostream>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100

struct SqStack {
	int* top;	//指向棧頂
	int* base;  //指向棧底
	int stacksize;  //棧的最大容量
};

//初始化棧
int initStack(SqStack& S) {
	S.base = new int[MAXSIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

//銷毀棧的操作
int DestoryStack(SqStack S) {
	if (S.base) {
		delete[] S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;  //設置為NULL是因為delete只是釋放內存，而S.base和S.top依然是指向一個內存地址
	}
	return OK;
}

//判斷棧是否為空
int StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return FALSE;
}

//求棧的長度
int StackLength(SqStack& S) {
	if (!S.base) return ERROR;
	return S.top - S.base;
}

//取得棧頂元素
int GetTop(SqStack& S,int& e) {
	if (S.base == S.top) return ERROR;
	e = *(S.top - 1);
	return OK;
}

//置空棧
int ClearStack(SqStack S) {
	if (S.base) S.top = S.base;
	return OK;
}

//入棧
int Push(SqStack& S, int e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
	return OK;
}

//出棧
int pop(SqStack& S, int& e) {
	if (S.top == S.base)return ERROR;
	e = *(--S.top);
	return OK;
}



int main() {
	return 0;
}
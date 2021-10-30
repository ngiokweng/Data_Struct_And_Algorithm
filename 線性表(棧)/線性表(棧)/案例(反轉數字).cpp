#include <iostream>
#include <string>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100

typedef char ElemType;

struct SqStack {
	ElemType* top;	//指向棧頂
	ElemType* base;  //指向棧底
	int stacksize;  //棧的最大容量
};

int InitStack(SqStack& S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

int Push(SqStack& S, ElemType e) {
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
	return OK;
}

int Pop(SqStack& S, ElemType& e) {
	if (S.top == S.base)return ERROR;
	e = *(--S.top);
	return OK;
}

int DestoryStack(SqStack& S) {
	if (S.base) {
		delete[] S.base;
		S.stacksize = 0;
		S.base = NULL;
		S.top = NULL;
	}
	return OK;
}

//10進制轉換為其他進制
void BaseChange(SqStack& S, int num,int target) {
	while (num != 0){
		int remainder = num % target;
		int n = 48;
		if (remainder > 9) {
			n = 55;
		}
		ElemType e = (ElemType)(remainder + n);
		Push(S, e);
		num /= target;
	}
	ElemType e;
	cout << "轉換後 ---> ";
	while (Pop(S,e)){
		cout << e;
	}
}

int main() {
	int num = 0;
	int target = 0;
	cout << "輸入數字：";
	cin >> num;
	cout << "要轉換為( x )進制，x = ";
	cin >> target;
	SqStack S;
	InitStack(S);
	BaseChange(S, num, target);
	DestoryStack(S);
	return 0;
}
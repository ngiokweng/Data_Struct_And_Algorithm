#include <iostream>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函數類型 其值是函數結果狀態代碼
typedef int Status;
typedef int ElemType;

#define MAXSIZE 1000

struct SqList {
	ElemType* elem;
	int length;
};

//返回線性表長度
int ListLength(SqList L) {
	return L.length;
}

//將線性表第i個元素返回給e
Status GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length)return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//在線性L表第i個位置插入e
Status ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)return ERROR;
	if (L.length == MAXSIZE)return ERROR;
	for (int index = L.length - 1; index >= i - 1; index--) {
		L.elem[index + 1] = L.elem[index];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

//查找與e相同的元素，找到返回序號，找不到返回0
Status LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)return i + 1;
	}
	return 0;
}

void ConnectList(SqList& La, SqList Lb) {
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	ElemType e;
	for (int i = 1; i <= Lb_len; i++) {
		GetElem(Lb, i, e);
		if (!LocateElem(La, e)) {
			ListInsert(La, ++La_len, e);
		}
	}
}


int main() {
	SqList La, Lb;
	La.elem = new ElemType[3]{ 1,2,3 };
	La.length = 3;
	Lb.elem = new ElemType[3]{ 2,3,4 };
	Lb.length = 3;
	ConnectList(La, Lb);
	for (int i = 0; i < La.length; i++) {
		cout << La.elem[i] << ", ";
	}
	delete La.elem;
	delete Lb.elem;
}
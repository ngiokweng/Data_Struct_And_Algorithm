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
typedef char ElemType;

#define MAXSIZE 1000

struct SqList {
	ElemType* elem;
	int length;
};

//初始化線性表
Status InitList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	return OK;
}

//銷毀已存在的線性表
void DestroyList(SqList& L) {
	if(L.elem)delete[] L.elem;
}

//清空線性表
void ClearList(SqList& L) {
	L.length = 0;
}

//檢查線性表是否為空
Status IsEmpty(SqList L) {
	if (L.length)return FALSE;
	return TRUE;
}

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
	if (i<1 || i>L.length+1)return ERROR;
	if(L.length == MAXSIZE)return ERROR;
	for (int index = L.length - 1; index >= i-1; index--) {
		L.elem[index + 1] = L.elem[index];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

//刪除線性表L第i個元素
Status ListDelete(SqList& L,int i) {
	if (i<1 || i>L.length)return ERROR;
	for (int index = i - 1; index < L.length-1; index++) {
		L.elem[index] = L.elem[index + 1];
	}
	L.length--;
	return OK;
}

//查找與e相同的元素，找到返回序號，找不到返回0
Status LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)return i + 1;
	}
	return 0;
}

int main() {

	return 0;
}
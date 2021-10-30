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

typedef int Status;

typedef struct Student {
	string name;
	int num;
}ElemType;

typedef struct LNode{
	Student data;
	LNode* next;
}*LinkList;

//單鏈表的初始化
Status InitList(LinkList& L) {  //形參的變化會導致實參的變化，所以用引用型的變量
	L = new LNode;
	L->next = NULL;
	return OK;
}

//判斷鏈表是否為空
int ListEmpty(LinkList L) {
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

//銷毀已存在的單鏈表
Status DestroyList(LinkList& L) {
	LNode* p = NULL;
	while (L != NULL) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

//清空單鏈表
Status ClearList(LinkList& L) {
	LNode *p,*q = NULL;
	p = L->next;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}

//求單鏈表的表長
int ListLength(LinkList L) {
	LinkList p;
	int count = 0;
	p = L->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

//取單鏈表第i個元素值
Status GetElem(LinkList L, int i, ElemType& e) {
	LinkList p = NULL;
	int count = 1;
	p = L->next;
	while (p && count<i)
	{
		p = p->next;
		++count;
	}
	if (!p || count > i) return ERROR;
	e = p->data;
	return OK;
}

//按值查找，返回地址
LNode* LocateElem1(LinkList L,ElemType e) {
	LinkList p;
	p = L->next;
	while ( p && (p->data.name != e.name ||
				p->data.num != e.num )) {
		p = p->next;
	}
	return p;
}

//按值查找，返回索引
int LocateElem2(LinkList L, ElemType e) {
	LinkList p;
	p = L->next;
	int count = 1;
	while (p && (p->data.name != e.name ||
		p->data.num != e.num )) {
		p = p->next;
		++count;
	}
	if (!p)return ERROR;
	return count;
}

//在第i個結點前插入新結點
Status InsertNode(LinkList& L, int i, ElemType e) {
	LinkList p = L;
	int count = 0;
	while (p && count < i - 1) {
		p = p->next;
		++count;
	}
	if (!p || count > i - 1)return ERROR;
	LNode* q = new LNode;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return OK;
}

//刪除第i個結點
Status DeleteNode(LinkList L, int i,ElemType& e) {
	LinkList p,q;
	int count = 1;
	p = L->next;
	while (p && count<i-1){
		p = p->next;
		++count;
	}
	if (!p || count > i )return ERROR;
	q = p->next->next;
	e = p->next->data;  //保存刪除結點的數據域
	delete p->next;
	p->next = q;
	return OK;
}

//單鏈表建立：頭插法
void CreateList_Front(LinkList& L,int n) {
	L = new LNode;
	L->next = NULL;

	for (int i = n; i >0 ; --i) {
		LNode* p = new LNode;
		//創建數據域
		cout << "第" << i << "個姓名：";
		cin >> p->data.name;
		cout << "第" << i << "個學號：";
		cin >> p->data.num;
		//創建指針域
		p->next = L->next;
		L->next = p;
	}
}

//單鏈表建立：尾插法
void CreateList_Back(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* q = L;

	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		//創建數據域
		cout << "第" << i << "個姓名：";
		cin >> p->data.name;
		cout << "第" << i << "個學號：";
		cin >> p->data.num;
		//創建指針域
		p->next = NULL;
		q->next = p;
		q = p;
	}
}

int main() {
}
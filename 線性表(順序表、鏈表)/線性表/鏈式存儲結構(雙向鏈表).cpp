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
typedef char ElemType;

typedef struct DuLNode {
	ElemType data;
	DuLNode* prior, * next;
}*DuLinkList;


//取鏈表第i個元素值，並返回該節點指針
DuLNode* GetElem(DuLinkList L, int i) {
	DuLNode* p = NULL;
	int count = 1;
	p = L->next;
	while (p && count < i){
		p = p->next;
		++count;
	}
	if (!L || count > i) return NULL;
	return p;
}

//插入
Status InsertNode(DuLinkList& L,int i,ElemType e) {
	DuLinkList p = NULL;
	if (!(p = GetElem(L, i))) return ERROR;
	DuLNode* q = new DuLNode;
	//設新插入節點的數據域和指針域
	q->data = e;
	q->next = p;
	q->prior = p->prior;
	//重設 新插入節點前面和後面節點的指針域
	p->prior->next = q;
	p->prior = q;
	return OK;
}

//刪除
Status DeleteNode(DuLinkList& L, int i, ElemType& e) {
	DuLinkList p = NULL;
	if (!(p = GetElem(L, i))) return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}

int main() {
}
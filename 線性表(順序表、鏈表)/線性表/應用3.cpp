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
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	LNode* next;
}*LinkList;


//單鏈表建立：尾插法
void CreateList_Back(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* q = L;

	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		//創建數據域
		p->data = i + 1+n;
		//創建指針域
		p->next = NULL;
		q->next = p;
		q = p;
	}
}

//銷毀已存在的單鏈表
Status DestroyList(LinkList& L) {
	LNode* p = NULL;
	while (L != NULL) {
		p = L;
		L = L->next;
		if (p) {
			delete p;
		}
	}
	return OK;
}

/************************核心代碼************************/
void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc) {
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc;
	pc = Lc = La;  //用La的頭結點作為Lc的頭結點

	while (pa&&pb)
	{
		if (pa->data > pb->data) {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else {
			pc->next = pa;
			pc =pa;
			pa = pa->next;
		}
	}
	pc->next = pa ? pa : pb;  //插入剩餘段
	delete Lb;  //釋放Lb頭結點

}
/************************核心代碼************************/

//For Test
int main() {
	LNode* La = NULL;
	LNode* Lb = NULL;
	LNode* Lc = new LNode;
	CreateList_Back(La, 10);
	CreateList_Back(Lb, 6);

	MergeList(La, Lb,Lc);
	LinkList pc = Lc->next;

	cout << "遍歷合並後的數據：" << endl;;
	while (pc)
	{
		cout << pc->data << ",";
		pc = pc->next;
	}
	cout << endl;
		
	DestroyList(Lc);
}
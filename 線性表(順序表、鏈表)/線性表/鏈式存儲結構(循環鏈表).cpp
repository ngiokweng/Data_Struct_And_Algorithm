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

typedef struct LNode {
	ElemType data;
	LNode* next;
}*LinkList;

//帶尾指針循環鏈表的合並
LinkList Connect(LinkList Ta, LinkList Tb) {  //Ta是鏈表a的尾指針，Tb同理
	LinkList p = Ta->next;  //保存Ta->next，即頭結點
	Ta->next = Tb->next->next;
	delete Tb->next;  //刪除Tb頭結點( Tb是最後，Tb->next就是頭結點 )
	Tb->next = p;
	
	return Tb;
}
//創建循環鏈表
void Create(LinkList& L,int n) {
	LinkList p = NULL;
	for (int i = 1; i <= n; i++) {
		if (!L) {
			L = new LNode;
			cin >> L->data;
			L->next = NULL;
			p = L;
			continue;
		}

		LinkList q = new LNode;
		cin >> q->data;
		if (i != n)
			q->next = NULL;
		else
			q->next = L;
		p->next = q;
		p = p->next;
	}
}

//遍歷循環鏈表
void PrintAll(LinkList L) {
	if (!L)return;
	LinkList head = L;
	while (L->next!=head) {
		cout << L->data << " ";
		L = L->next;
	}
	cout << L->data << endl;
}

int main() {
	LinkList L = NULL;
	Create(L, 5);
	PrintAll(L);
	return 0;
}
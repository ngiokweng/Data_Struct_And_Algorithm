#include <iostream>
#include <string>
using namespace std;

//��Ƶ��G���A�N�X
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

//�a�����w�`������X��
LinkList Connect(LinkList Ta, LinkList Tb) {  //Ta�O���a�������w�ATb�P�z
	LinkList p = Ta->next;  //�O�sTa->next�A�Y�Y���I
	Ta->next = Tb->next->next;
	delete Tb->next;  //�R��Tb�Y���I( Tb�O�̫�ATb->next�N�O�Y���I )
	Tb->next = p;
	
	return Tb;
}
//�Ыش`�����
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

//�M���`�����
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
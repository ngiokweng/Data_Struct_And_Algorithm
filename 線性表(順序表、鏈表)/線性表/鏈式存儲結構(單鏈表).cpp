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

typedef struct Student {
	string name;
	int num;
}ElemType;

typedef struct LNode{
	Student data;
	LNode* next;
}*LinkList;

//�������l��
Status InitList(LinkList& L) {  //�ΰѪ��ܤƷ|�ɭP��Ѫ��ܤơA�ҥH�ΤޥΫ����ܶq
	L = new LNode;
	L->next = NULL;
	return OK;
}

//�P�_���O�_����
int ListEmpty(LinkList L) {
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

//�P���w�s�b�������
Status DestroyList(LinkList& L) {
	LNode* p = NULL;
	while (L != NULL) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

//�M�ų����
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

//�D��������
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

//��������i�Ӥ�����
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

//���Ȭd��A��^�a�}
LNode* LocateElem1(LinkList L,ElemType e) {
	LinkList p;
	p = L->next;
	while ( p && (p->data.name != e.name ||
				p->data.num != e.num )) {
		p = p->next;
	}
	return p;
}

//���Ȭd��A��^����
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

//�b��i�ӵ��I�e���J�s���I
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

//�R����i�ӵ��I
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
	e = p->next->data;  //�O�s�R�����I���ƾڰ�
	delete p->next;
	p->next = q;
	return OK;
}

//�����إߡG�Y���k
void CreateList_Front(LinkList& L,int n) {
	L = new LNode;
	L->next = NULL;

	for (int i = n; i >0 ; --i) {
		LNode* p = new LNode;
		//�Ыؼƾڰ�
		cout << "��" << i << "�өm�W�G";
		cin >> p->data.name;
		cout << "��" << i << "�ӾǸ��G";
		cin >> p->data.num;
		//�Ыث��w��
		p->next = L->next;
		L->next = p;
	}
}

//�����إߡG�����k
void CreateList_Back(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* q = L;

	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		//�Ыؼƾڰ�
		cout << "��" << i << "�өm�W�G";
		cin >> p->data.name;
		cout << "��" << i << "�ӾǸ��G";
		cin >> p->data.num;
		//�Ыث��w��
		p->next = NULL;
		q->next = p;
		q = p;
	}
}

int main() {
}
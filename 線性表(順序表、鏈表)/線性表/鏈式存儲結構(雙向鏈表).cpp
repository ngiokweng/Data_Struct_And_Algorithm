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

typedef struct DuLNode {
	ElemType data;
	DuLNode* prior, * next;
}*DuLinkList;


//������i�Ӥ����ȡA�ê�^�Ӹ`�I���w
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

//���J
Status InsertNode(DuLinkList& L,int i,ElemType e) {
	DuLinkList p = NULL;
	if (!(p = GetElem(L, i))) return ERROR;
	DuLNode* q = new DuLNode;
	//�]�s���J�`�I���ƾڰ�M���w��
	q->data = e;
	q->next = p;
	q->prior = p->prior;
	//���] �s���J�`�I�e���M�᭱�`�I�����w��
	p->prior->next = q;
	p->prior = q;
	return OK;
}

//�R��
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
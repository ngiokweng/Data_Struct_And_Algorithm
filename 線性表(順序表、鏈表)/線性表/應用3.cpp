#include <iostream>
using namespace std;
//��Ƶ��G���A�N�X
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


//�����إߡG�����k
void CreateList_Back(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* q = L;

	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		//�Ыؼƾڰ�
		p->data = i + 1+n;
		//�Ыث��w��
		p->next = NULL;
		q->next = p;
		q = p;
	}
}

//�P���w�s�b�������
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

/************************�֤ߥN�X************************/
void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc) {
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc;
	pc = Lc = La;  //��La���Y���I�@��Lc���Y���I

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
	pc->next = pa ? pa : pb;  //���J�Ѿl�q
	delete Lb;  //����Lb�Y���I

}
/************************�֤ߥN�X************************/

//For Test
int main() {
	LNode* La = NULL;
	LNode* Lb = NULL;
	LNode* Lc = new LNode;
	CreateList_Back(La, 10);
	CreateList_Back(Lb, 6);

	MergeList(La, Lb,Lc);
	LinkList pc = Lc->next;

	cout << "�M���X�ë᪺�ƾڡG" << endl;;
	while (pc)
	{
		cout << pc->data << ",";
		pc = pc->next;
	}
	cout << endl;
		
	DestroyList(Lc);
}
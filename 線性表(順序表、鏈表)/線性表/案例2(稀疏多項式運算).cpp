#include <iostream>
using namespace std;

struct Polynomial {
	int exponent;  //计
	double coefficient; //╰计
};

typedef struct LNode {
	Polynomial data;
	LNode* next;
}*LinkList;

void CreatePoly(LinkList& L,int num) {
	L = new LNode;
	L->next = NULL;
	LinkList p = L;
	for (int i = 0; i < num; ++i) {
		LNode* q = new LNode;
		q->next = NULL;
		cout << "材" << i + 1 << "兜╰计";
		cin >> q->data.coefficient;
		cout << "材" << i + 1 << "兜计";
		cin >> q->data.exponent;
		p->next = q;
		p = p->next;
	}
}

//э玡
//void AddTwoPoly(LinkList La, LinkList Lb, LinkList& Lc) {
//	Lc = new LNode;
//	Lc->next = NULL;
//
//	LinkList pa = La->next,pb = Lb->next,pc = Lc;
//
//	LinkList q;
//	while (pa && pb){
//		q = new LNode;
//		q->next = NULL;
//		if (pa->data.exponent > pb->data.exponent) {
//			q->data.coefficient = pb->data.coefficient;
//			q->data.exponent = pb->data.exponent;
//			pb = pb->next;
//
//			pc->next = q;
//			pc = pc->next;
//		}
//		else if (pa->data.exponent < pb->data.exponent) {
//			q->data.coefficient = pa->data.coefficient;
//			q->data.exponent = pa->data.exponent;
//			pa = pa->next;
//
//			pc->next = q;
//			pc = pc->next;
//		}
//		else {
//			q->data.coefficient = pa->data.coefficient + pb->data.coefficient;
//			q->data.exponent = pa->data.exponent;
//			pa = pa->next;
//			pb = pb->next;
//
//			pc->next = q;
//			pc = pc->next;
//		}
//	}
//	while (pa) {
//		q = new LNode;
//		q->next = NULL;
//
//		q->data.coefficient = pa->data.coefficient;
//		q->data.exponent = pa->data.exponent;
//		pa = pa->next;
//
//		pc->next = q;
//		pc = pc->next;
//	}
//	while (pb) {
//		q = new LNode;
//		q->next = NULL;
//
//		q->data.coefficient = pb->data.coefficient;
//		q->data.exponent = pb->data.exponent;
//		pb = pb->next;
//
//		pc->next = q;
//		pc = pc->next;
//	}
//}

//э
void AddTwoPoly(LinkList La, LinkList Lb, LinkList& Lc) {
	Lc = La;
	LinkList pa = La->next, pb = Lb->next, pc = Lc;

	while (pa && pb) {

		if (pa->data.exponent > pb->data.exponent) {

			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
		}
		else if (pa->data.exponent < pb->data.exponent) {

			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
		else {
			if (pa->data.coefficient + pb->data.coefficient == 0) {
				LinkList p, q;
				p = pa;
				q = pb;
				pa = pa->next;
				pb = pb->next;
				delete p;
				delete q;
			}

			LinkList c = pb;
			pa->data.coefficient += pb->data.coefficient;
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
			delete c;
		}
	}
	if (pa)pc->next = pa;
	if (pb)pc->next = pb;

	delete Lb;
}

void TraverseList(LinkList L) {
	LinkList p = L->next;
	while (p)
	{
		cout << "计" << p->data.exponent << " , ╰计" << p->data.coefficient << endl;
		p = p->next;
	}
}

void DestoryList(LinkList L) {
	LinkList p = NULL;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
}


int main() {
	LinkList La, Lb, Lc;

	cout << "La兜Α" << endl;
	CreatePoly(La,3);
	cout << "Lb兜Α" << endl;
	CreatePoly(Lb,3);

	AddTwoPoly(La, Lb, Lc);

	TraverseList(Lc);
	
	DestoryList(Lc);
	return 0;
}
#include <iostream>
using namespace std;

typedef int ElemType;

struct SqList {
	ElemType* elem;
	int length;
};

/************************�֤ߥN�X************************/
void MergeList(SqList La, SqList Lb, SqList& Lc) {
	ElemType* pa = La.elem;
	ElemType* pb = Lb.elem;
	Lc.length = La.length + Lb.length;
	Lc.elem = new ElemType[Lc.length];
	ElemType* pc = Lc.elem;
	ElemType* pa_last, * pb_last;
	pa_last = pa + La.length - 1;
	pb_last = pb + La.length - 1;

	while (pa <= pa_last && pb <= pb_last) {  //��Ӫ��D��
		if (*pa <= *pb) {
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}
	while (pa <= pa_last)*pc++ = *pa++;   //Lb��w��̧��A�NLa��ѤU���[��Lc��
	while (pb <= pb_last)*pc++ = *pb++;  //La��w��̧��A�NLb��ѤU���[��Lc��
}
/************************�֤ߥN�X************************/

//For Test
int main() {
	SqList La, Lb, Lc;
	La.elem = new ElemType[3]{ 1,2,3 };
	La.length = 3;
	Lb.elem = new ElemType[3]{ 2,3,4 };
	Lb.length = 3;
	MergeList(La, Lb, Lc);
	for (int i = 0; i < Lc.length; i++) {
		cout << Lc.elem[i] << ", ";
	}
	delete La.elem;
	delete Lb.elem;
	delete Lc.elem;
}
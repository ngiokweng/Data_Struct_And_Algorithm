#include <iostream>
using namespace std;

#define MAX 20

struct MyList {
	int* data;
	int length;
};

void InitList(MyList& L) {
	L.data = new int[MAX];
	L.length = 0;
}

void CreateList(MyList& L,int num) {
	for (int i = 0; i < num; i++) {
		cout << "輸入" << i <<"次項系數" << endl;
		cin >> L.data[i];
		L.length++;
	}
}

void AddTwoList(MyList La, MyList Lb, MyList& Lc) {
	for (int i = 0; i < La.length && i < Lb.length; i++) {
		Lc.data[i] = La.data[i] + Lb.data[i];
		Lc.length++;
	}

	if (La.length == Lb.length)return;

	while (Lc.length == La.length){
		Lc.data[Lc.length] = Lb.data[La.length++];
		Lc.length++;
		if (La.length == Lb.length)return;
	}
	while (Lc.length == Lb.length) {
		Lc.data[Lc.length] = La.data[Lb.length++];
		Lc.length++;
		if (La.length == Lb.length)return;
	}
	

}

int main() {
	MyList La, Lb, Lc;
	InitList(La);
	InitList(Lb);
	InitList(Lc);
	cout << "輸入List(a)的各項系數：" << endl;
	CreateList(La, 4);
	cout << "輸入List(b)的各項系數：" << endl;
	CreateList(Lb, 5);
	AddTwoList(La, Lb, Lc);

	for (int i = 0; i < Lc.length; i++) {
		cout << "x的" << i << "次方系數為：" << Lc.data[i] << endl;;
	}
	delete La.data;
	delete Lb.data;
	delete Lc.data;
	return 0;
}
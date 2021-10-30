#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 100

struct Book {
	string name;
	int id;
	int price;
};

struct BookList {
	Book* elem;
	int length;
};

void CreateList(BookList& L,int num) {
	L.elem = new Book[MAXSIZE];
	L.length = 0;

	for (int i = 0; i < num; ++i) {
		cout << "第" << i + 1 << "本的書的名字：";
		cin >> L.elem[i].name;
		cout << "第" << i + 1 << "本的書的ID：";
		cin >> L.elem[i].id;
		cout << "第" << i + 1 << "本的書的價錢：";
		cin >> L.elem[i].price;
		L.length++;
	}
}

void DestoryList(BookList L) {
	if (L.elem) {
		delete[] L.elem;
		L.elem = NULL;
	}
}

//增加操作
void AddNewBook(BookList& L,int i,Book book) {
	if (i<1 || i>L.length+1) return;

	int length = L.length;

	for (int j = length; j >= i; --j) {
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = book;
	L.length++;
}

//刪除操作
void DeleteBook(BookList& L, int i) {
	if (i<1 || i>L.length) return;

	int length = L.length;

	for (int j = i-1; j < length-1; ++j) {
		L.elem[j] = L.elem[j+1];
	}
	--L.length;
}
//修改操作
void ReviseBook(BookList& L, int i) {
	if (i<1 || i>L.length) return;

	cout << "(修改)第" << i  << "本的書的名字：";
	cin >> L.elem[i - 1].name;
	cout << "(修改)第" << i  << "本的書的ID：";
	cin >> L.elem[i - 1].id;
	cout << "(修改)第" << i  << "本的書的價錢：";
	cin >> L.elem[i - 1].price;
}

int main() {
	BookList L;
	Book newBook = { "7",7,7};

	CreateList(L, 3);
	AddNewBook(L, 2, newBook);
	DeleteBook(L, 2);
	ReviseBook(L, 1);
	for (int i = 0; i < L.length; i++) {
		cout << "書名：" << L.elem[i].name << " ID：" << L.elem[i].id << " 價錢：" << L.elem[i].price << endl;
	}
	DestoryList(L);
	return 0;
}
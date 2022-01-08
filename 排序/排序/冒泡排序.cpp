#include <iostream>
using namespace std;

#define MAXSIZE 20
typedef int KeyType;
typedef char InfoType;

struct RedType {  //Record Type
	KeyType key; //����r
	InfoType otherinfo;  //��L�ƾڶ�
};

struct SqList {							// �w�q���Ǫ����c
	RedType r[MAXSIZE + 1];  // �s�x���Ǫ��V�q
												//r[0]�@��@��L�νw�R��
	int length;
};

//�_�w�Ƨ�
void bubble_sort(SqList& L) {
	bool flag = true;
	for (int i = 1; i <= L.length-1 && flag; i++) {
		for (int j = 1; j <= L.length - i; j++) {
			flag = false;
			if (L.r[j].key > L.r[j + 1].key) {
				L.r[j].key = L.r[j].key ^ L.r[j + 1].key;
				L.r[j+1].key = L.r[j].key ^ L.r[j + 1].key;
				L.r[j].key = L.r[j].key ^ L.r[j + 1].key;
				flag = true;
			}
		}
	}
}

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

//��ܱƧ�1�G������ܱƧ�
void SelectSort(SqList& L) {
	for (int i = 1; i < L.length; i++) {
		int min_index = i;
		for (int j = i + 1; j <= L.length; j++) {
			if (L.r[j].key < L.r[min_index].key)min_index = j;
		}
		if (min_index != i) {
			RedType tmp = L.r[i];
			L.r[i] = L.r[min_index];
			L.r[min_index] = tmp;
		}
	}
}
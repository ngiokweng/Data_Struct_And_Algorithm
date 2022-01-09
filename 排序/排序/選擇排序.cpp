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
/*��ܱƧ�2�G��Ƨ�*/
void HeapAdjust(SqList& L, int s, int m) {
	/*�w�XL.r[s..m]���O��������r��L.r[s]���~�������諸�w�q�A
		����ƽվ�L.r[s]������r�A��L.r[s..m]�����@�Ӥj�ڰ�
	*/
	RedType rc = L.r[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j].key < L.r[j + 1].key)++j;
		if (rc.key >= L.r[j].key)break;
		L.r[s] = L.r[j]; s = j;  //rc�����b��ms�W
	}
	L.r[s] = rc; //���J
}

void HeapSort(SqList& L) {
	int i;
	for (i = L.length / 2; i >= 1; i--)
		HeapAdjust(L, i, L.length);
	for (i = L.length; i > 1; i--) {
		RedType tmp = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = tmp;
		HeapAdjust(L, 1, i - 1);
	}
}
//for test
int main() {
	SqList L;
	L.length = 0;
	for (int i = 1; i < 5; i++) {
		cin >> L.r[i].key;
		L.length++;
	}
	HeapSort(L);
	for (int i = 1; i < 5; i++) {
		cout << L.r[i].key << " ";
	}
}
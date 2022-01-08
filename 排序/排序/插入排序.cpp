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

//���J�Ƨ�1�G�������J�Ƨ�
void InsertSort(SqList& L) {
	//(�Ѥp��j��)
	int i, j;
	for (i = 2; i <= L.length; i++) {  //�`���� i = 2 �}�l�A�]�� 0 ����L��
		if (L.r[i].key < L.r[i - 1].key) {  //�p�G i �� i-1 �j�N���α�
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[j].key > L.r[0].key; j--) {  //��i�N�n�Q���J�������j�p�󥦫e�����@�ǡi�w�Ʀn�Ǫ������ɡj�A�N���Ǥ����Ჾ
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];  //�W�z�`��������Aj + 1����m�N�O�i�ݴ��J�j����m
		}
	}
}

//���J�Ƨ�2�G�G�����J�Ƨ�(���G���d��)
void InsertSort2(SqList& L) {
	int i, j;
	for (i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];  //�N��e���J�����s�b"��L"
		int first = 1, last = i - 1,mid;
		while (first <= last) {
			mid = (first + last) / 2;
			if (L.r[0].key > L.r[mid].key)
				first = mid + 1;
			else
				last = mid - 1;
		}//�`�������ɡAlast + 1���i���J��m�j
		for (j = i - 1; j >= last + 1; j--)L.r[j + 1] = L.r[j];
		L.r[last + 1] = L.r[0];  //���J�쥿�T��m
	}
}

int main() {
	return 0;
}
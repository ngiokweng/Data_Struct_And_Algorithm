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

int main() {
	return 0;
}
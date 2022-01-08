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

//�洫�Ƨ�1�G�_�w�Ƨ�
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

/*�洫�Ƨ�2�G�ֳt�Ƨ�*/
int Partition(SqList& L, int low, int high) {
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high) {
		while (low<high && L.r[high].key >= pivotkey)high--;
		L.r[low] = L.r[high];
		while (low<high && L.r[low].key <= pivotkey)low++;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList& L, int low, int high) {
	if (low < high) { //���פj��1
		int pivotloc = Partition(L, low, high);
		//�NL.r[low...high]�@�����G�Apivotloc���϶b�����Ʀn�Ǫ���m
		QSort(L, low, pivotloc - 1); //��C�l���k�Ƨ�
		QSort(L,pivotloc + 1,high); //�ﰪ�l���k�Ƨ�
	}
}

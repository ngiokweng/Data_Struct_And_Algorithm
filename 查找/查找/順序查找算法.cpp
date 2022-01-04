#include <iostream>
using namespace std;

typedef int KeyType;

struct ElemType {
	KeyType key; //�����
};

struct SSTable {
	ElemType* R; //���}
	int length;  //���
};

// �]�m�ʵ��諸���Ǭd���k
int Sq_Search(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int pos;
	for (pos = ST.length; ST.R[pos].key != key; pos--);
	//��^�D0�N����A��^0�N��䤣��
	return pos; 
}

int main() {
	/*For Test*/
	SSTable ST;
	ST.R = new ElemType[4];
	ST.length = 4;
	for (int i = 1; i <= ST.length; i++)ST.R[i].key = i;
	cout << Sq_Search(ST, 2) << endl;
	return 0;
}
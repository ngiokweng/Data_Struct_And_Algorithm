#include <iostream>
using namespace std;

typedef int KeyType;

struct ElemType {
	KeyType key; //關鍵域
};

struct SSTable {
	ElemType* R; //表基址
	int length;  //表長
};

// 設置監視哨的順序查找算法
int Sq_Search(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int pos;
	for (pos = ST.length; ST.R[pos].key != key; pos--);
	//返回非0代表找到，返回0代表找不到
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
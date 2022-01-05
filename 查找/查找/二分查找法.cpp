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

// 二分查找算法
int Bin_Search(SSTable ST, KeyType key) {
	int first = 1, last = ST.length;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (ST.R[mid].key == key)
			return mid;
		else if (ST.R[mid].key < key)
			first = mid + 1;
		else 
			last = mid - 1;

	}
	return 0;
}

int main() {
	/*For Test*/
	SSTable ST;
	ST.R = new ElemType[4];
	ST.length = 4;
	for (int i = 1; i <= ST.length; i++)ST.R[i].key = i+2;
	cout << Bin_Search(ST, 3) << endl;
	return 0;
}
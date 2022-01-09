#include <iostream>
using namespace std;

#define MAXSIZE 20
typedef int KeyType;
typedef char InfoType;

struct RedType {  //Record Type
	KeyType key; //關鍵字
	InfoType otherinfo;  //其他數據項
};

struct SqList {							// 定義順序表的結構
	RedType r[MAXSIZE + 1];  // 存儲順序表的向量
												//r[0]一般作哨兵或緩沖區
	int length;
};

//選擇排序1：直接選擇排序
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
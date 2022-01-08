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

//冒泡排序
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

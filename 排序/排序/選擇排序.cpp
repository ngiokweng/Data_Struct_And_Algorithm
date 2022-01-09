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
/*選擇排序2：堆排序*/
void HeapAdjust(SqList& L, int s, int m) {
	/*已合L.r[s..m]中記錄的關鍵字除L.r[s]之外均滿足堆的定義，
		本函數調整L.r[s]的關鍵字，使L.r[s..m]成為一個大根堆
	*/
	RedType rc = L.r[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j].key < L.r[j + 1].key)++j;
		if (rc.key >= L.r[j].key)break;
		L.r[s] = L.r[j]; s = j;  //rc應插在位置s上
	}
	L.r[s] = rc; //插入
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
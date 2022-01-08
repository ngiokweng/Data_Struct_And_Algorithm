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

//交換排序1：冒泡排序
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

/*交換排序2：快速排序*/
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
	if (low < high) { //長度大於1
		int pivotloc = Partition(L, low, high);
		//將L.r[low...high]一分為二，pivotloc為樞軸元素排好序的位置
		QSort(L, low, pivotloc - 1); //對低子表遞歸排序
		QSort(L,pivotloc + 1,high); //對高子表遞歸排序
	}
}

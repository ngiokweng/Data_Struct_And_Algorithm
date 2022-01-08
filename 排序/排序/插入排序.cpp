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

//插入排序1：直接插入排序
void InsertSort(SqList& L) {
	//(由小到大排)
	int i, j;
	for (i = 2; i <= L.length; i++) {  //循環由 i = 2 開始，因為 0 為哨兵位
		if (L.r[i].key < L.r[i - 1].key) {  //如果 i 比 i-1 大就不用排
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[j].key > L.r[0].key; j--) {  //當【將要被插入的元素】小於它前面的一些【已排好序的元素時】，將那些元素後移
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];  //上述循環完成後，j + 1的位置就是【待插入】的位置
		}
	}
}

//插入排序2：二分插入排序(基於二分查找)
void InsertSort2(SqList& L) {
	int i, j;
	for (i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];  //將當前插入元素存在"哨兵"
		int first = 1, last = i - 1,mid;
		while (first <= last) {
			mid = (first + last) / 2;
			if (L.r[0].key > L.r[mid].key)
				first = mid + 1;
			else
				last = mid - 1;
		}//循環結束時，last + 1為【插入位置】
		for (j = i - 1; j >= last + 1; j--)L.r[j + 1] = L.r[j];
		L.r[last + 1] = L.r[0];  //插入到正確位置
	}
}

/*插入排序3：希爾排序*/
void ShellInsert(SqList& L, int dk) {
	//對順序表L進行一趟增量為dk的Shell排序，dk為步長因子
	int i, j;
	for (i = dk + 1; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i - dk];
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j = j - dk)
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}

	}
}
void ShellSort(SqList& L, int dlta[], int t) {
	//按增量序列dlta[0..t-1]對順序表L作希爾排序
	for (int k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);
}

int main() {
	return 0;
}
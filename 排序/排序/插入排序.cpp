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

int main() {
	return 0;
}
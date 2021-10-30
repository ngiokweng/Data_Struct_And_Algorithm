#include <iostream>
using namespace std;

//使用順序存儲
typedef struct HTNode {
	int weight;  
	int lchild, rchild, parent;
}*HuffmanTree;

//以s1,s2返回兩個weight最小的節點的索引
void select(HuffmanTree H,int n, int& s1, int& s2) {
	
	s1 = 0;
	s2 = 0;

	//先隨便找一個parent為0的節點的索引
	for (int i = 1; i < n; i++) {
		if (H[i].parent == 0) {
			s1 = i;
			break;
		}
	}

	//然後先找出第一個最小
	for (int i = 1; i < n; i++) {
		if (H[i].parent != 0)continue;
		if (H[i].weight < H[s1].weight) s1 = i;
	}

	for (int i = 1; i < n; i++) {
		if (H[i].parent == 0 && i!=s1) {
			s2 = i;
			break;
		}
	}

	//再找出第二個最小
	for (int i = 1; i < n; i++) {
		if (H[i].parent == 0 && i != s1) {
			if (H[i].weight < H[s2].weight) {
				s2 = i;
				break;
			}
		}
	}
}

//哈夫曼樹構造算法
void CreateHuffmanTree(HuffmanTree& H, int n) {
	///////////////////// 初始化的過程 /////////////////////
	if (n <= 1)return;
	int m = 2 * n - 1;  //數組共有2n - 1個元素
	H = new HTNode[m+1];  //0號下標不用，H[m]表示根結點
	for (int i = 1; i <= m; i++) {
		H[i].lchild = 0;
		H[i].rchild = 0;
		H[i].parent = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> H[i].weight;
	}

	///////////////////// 具體實現 /////////////////////
	for (int i = n + 1; i <= m; i++) {
		int s1, s2;
		select(H, i, s1, s2);
		H[i].weight = H[s1].weight + H[s2].weight;
		H[i].lchild = s1;
		H[i].rchild = s2;
		H[s1].parent = i;
		H[s2].parent = i;
	}
}


//哈夫曼編碼算法
typedef char** HuffmanCode;
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode& HC,int n) {
	//從葉子到根逆向求每個字符的哈夫曼編碼，存儲在編碼表HC中
	HC = new char* [n + 1];   //分配n個字符編碼的頭指針矢量
	char* cd = new char[n];   //分配臨時存放編碼的動態數組
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		
		while (f != 0) {    //從葉子結點開始向上回溯，直到根結點
			--start;   //回溯一次start向前指一個位置
			if (HT[f].lchild == c) {
				cd[start] = '0';    //結點c是f的左孩子，則生成代碼0
			}
			else {
				cd[start] = '1';   //結點c是f的右孩子，則生成代碼1
			}
			c = f; f = HT[f].parent;  //繼續向上回溯，直到向到第i個字符的編碼
		}
		HC[i] = new char[n - start];   //為第i個字符串編碼分配空間
		strcpy_s(HC[i], n - start,&cd[start]);   //將求得的編碼從臨時空間cd複製到HC的當前行中
	}
	delete[] cd;
}
int main() {
	/********************【示例】哈夫曼樹構造算法 (示例輸入1 3 7 8) **********************/
	HuffmanTree H = NULL;
	int n = 4;
	CreateHuffmanTree(H, n);
	for (int i = 1; i <= n*2-1; i++) {
		cout << H[i].weight << " ";
	}
	cout << endl;
	cout << endl;

	/********************【示例】哈夫曼編碼算法 **********************/
	for (int i = 1; i <= n; i++) {
		cout << H[i].weight << " ";
	}
	cout <<"對應的哈夫曼編碼為：" << endl;
	HuffmanCode HC = NULL;
	CreateHuffmanCode(H, HC, n);
	for (int i = 1; i <= n; i++) {
		cout << HC[i] << " ";
	}
	
	delete[] H;
	delete[] HC;
}
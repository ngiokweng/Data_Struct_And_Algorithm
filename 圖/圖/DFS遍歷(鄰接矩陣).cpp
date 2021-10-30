#include <iostream>
using namespace std;

#define MVNum 100  //最大頂點數
typedef char VerTexType;  //設頂點的數據類型為char
typedef int ArcType;   //設邊的權值類型為整型


struct AMGraph {  //Adjacency Matrix Graph 鄰接矩陣圖
	VerTexType vexs[MVNum];  //頂點表
	ArcType arcs[MVNum][MVNum];  //鄰接矩陣
	int vexNum, arcNum;  //圖當前的頂點數和邊數
};

//返回target在頂點表中的索引
int LocateVex(AMGraph G, VerTexType target) {
	for (int i = 0; i < G.vexNum; i++) {
		if (G.vexs[i] == target)return i;
	}
	return -1;
}

//創建無向圖
void CreateUDG(AMGraph& G) {
	cin >> G.vexNum >> G.arcNum; //輸入頂點數、邊數

	//輸入頂點
	for (int i = 0; i < G.vexNum; i++)
		cin >> G.vexs[i];

	//初始化鄰接矩陣的每一個值為MaxInt
	for (int i = 0; i < G.vexNum; i++)
		for (int j = 0; j < G.vexNum; j++)
			G.arcs[i][j] = 0;

	for (int k = 0; k < G.arcNum; k++) {
		VerTexType vex1, vex2;
		int i, j, w;
		cin >> vex1 >> vex2;  //輸入【邊】所連接的兩頂點
		cin >> w;  //輸入權值
		i = LocateVex(G, vex1);
		j = LocateVex(G, vex2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];  //因為是對稱矩陣
	}

}

//DFS
bool visited[MVNum] = { false };  //輔助數組，記錄已遍歷過的頂點
void DFS(AMGraph& G, int v) {
	cout << G.vexs[v] << " ";
	visited[v] = true;
	for (int i = 0; i < G.vexNum; i++) {
		if ((G.arcs[v][i] != 0) && (!visited[i]))
			DFS(G, i);
	}
}

//test data：3 2 A B C A B 1 A C 2
int main() {
	AMGraph G;
	CreateUDG(G);
	for (int i = 0; i < G.vexNum; i++) {
		for (int j = 0; j < G.vexNum; j++) {
			cout << G.arcs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	DFS(G, 1);

	return 0;
}
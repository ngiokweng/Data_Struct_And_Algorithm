#include <iostream>
using namespace std;

#define MVNum 100  //最大頂點數
typedef char VerTexType;  //設頂點的數據類型為char
typedef int ArcType;   //設邊的權值類型為整型
typedef int OtherInfo;   //和邊相關的信息的類型

//弧(邊)的結點結構
struct ArcNode {
	int adjvex;   //該邊所指向的頂點的位置
	ArcNode* nextarc;  //指向下一條邊的指針
	OtherInfo info;   //和邊相關的信息(如：權)
};

//頂點的結點結構
struct VNode {
	VerTexType data;  //頂點信息
	ArcNode* firstarc;  //指向第一條依附該頂點的邊的指針
};

//圖的結構
struct ALGraph {
	VNode vertices[MVNum];  //頂點的集合
	int vexNum, arcNum;  //圖的當前頂點數和弧數
};

//返回指定頂點在頂點數組的下標
int LocateVex(ALGraph G, VerTexType target) {
	for (int i = 0; i < G.vexNum; i++) {
		if (G.vertices[i].data == target)
			return i;
	}
	return -1;
}

//創建鄰接表
void CreateUDG(ALGraph& G) {
	cin >> G.vexNum >> G.arcNum;  //輸入總頂點數和邊數
	//輸入頂點
	for (int i = 0; i < G.vexNum; i++) {
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}


	for (int i = 0; i < G.arcNum; i++) {
		VerTexType v1 = 0, v2 = 0;
		int j = 0, k = 0;
		cin >> v1 >> v2;  //輸入各邊所連接的兩頂點
		j = LocateVex(G, v1);
		k = LocateVex(G, v2);

		//////////////// 因為是無向圖，所以要連兩次 ////////////////
		ArcNode* p1 = new ArcNode;
		p1->adjvex = k;
		p1->info = 0;
		p1->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p1;

		ArcNode* p2 = new ArcNode;
		p2->adjvex = j;
		p2->info = 0;
		p2->nextarc = G.vertices[k].firstarc;
		G.vertices[k].firstarc = p2;
	}

}


#include <queue>
//標誌訪問過的數組
bool visited[MVNum] = { false };
/*********************  BFS(廣度優先搜索) ***************************/
void BFS(ALGraph& G, int v) {
	
	//最外層呢個for循環，是為左防止【非連通圖】的情況
	for (int i = 0; i < G.vexNum; i++) {
		if (visited[v])continue;   //如果訪問過，就直接continue

		/* 
		大致解釋：以隊列的方式實現，先將隨便一個頂點入隊，再在while將其出隊，
		並【訪問】其所有【未被訪問過】的邊結點，且將那些邊結點指向的頂點入隊 ，
		重複上述步驟，即可將其中一個連通分量遍歷完成
		*/
		visited[v] = true;
		cout << G.vertices[v].data<<" ";
		queue<int> q;
		q.push(v);
		while (!q.empty()) {
			int vex = q.front();
			q.pop();
			for (ArcNode* tmp = G.vertices[vex].firstarc; tmp != NULL; tmp = tmp->nextarc) {
				if (!visited[tmp->adjvex]) {
					visited[tmp->adjvex] = true;
					cout << G.vertices[tmp->adjvex].data << " ";
					q.push(tmp->adjvex);
				}

			}
		}
	}
}
/*****************************************************************/

//for test：
//2 1 A B A B
//3 2 A B C A B A C
int main() {
	ALGraph G;
	CreateUDG(G);
	for (int i = 0; i < G.vexNum; i++) {
		cout << G.vertices[i].data << " ";
		ArcNode* p = G.vertices[i].firstarc;
		while (p) {
			cout << p->adjvex << " ";
			p = p->nextarc;
		}
		cout << endl;
	}

	BFS(G, 0);

	return 0;
}
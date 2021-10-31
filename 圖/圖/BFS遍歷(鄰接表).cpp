#include <iostream>
using namespace std;

#define MVNum 100  //�̤j���I��
typedef char VerTexType;  //�]���I���ƾ�������char
typedef int ArcType;   //�]�䪺�v���������㫬
typedef int OtherInfo;   //�M��������H��������

//��(��)�����I���c
struct ArcNode {
	int adjvex;   //����ҫ��V�����I����m
	ArcNode* nextarc;  //���V�U�@���䪺���w
	OtherInfo info;   //�M��������H��(�p�G�v)
};

//���I�����I���c
struct VNode {
	VerTexType data;  //���I�H��
	ArcNode* firstarc;  //���V�Ĥ@���̪��ӳ��I���䪺���w
};

//�Ϫ����c
struct ALGraph {
	VNode vertices[MVNum];  //���I�����X
	int vexNum, arcNum;  //�Ϫ���e���I�ƩM����
};

//��^���w���I�b���I�Ʋժ��U��
int LocateVex(ALGraph G, VerTexType target) {
	for (int i = 0; i < G.vexNum; i++) {
		if (G.vertices[i].data == target)
			return i;
	}
	return -1;
}

//�ЫؾF����
void CreateUDG(ALGraph& G) {
	cin >> G.vexNum >> G.arcNum;  //��J�`���I�ƩM���
	//��J���I
	for (int i = 0; i < G.vexNum; i++) {
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}


	for (int i = 0; i < G.arcNum; i++) {
		VerTexType v1 = 0, v2 = 0;
		int j = 0, k = 0;
		cin >> v1 >> v2;  //��J�U��ҳs�����⳻�I
		j = LocateVex(G, v1);
		k = LocateVex(G, v2);

		//////////////// �]���O�L�V�ϡA�ҥH�n�s�⦸ ////////////////
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
//�лx�X�ݹL���Ʋ�
bool visited[MVNum] = { false };
/*********************  BFS(�s���u���j��) ***************************/
void BFS(ALGraph& G, int v) {
	
	//�̥~�h�O��for�`���A�O��������i�D�s�q�ϡj�����p
	for (int i = 0; i < G.vexNum; i++) {
		if (visited[v])continue;   //�p�G�X�ݹL�A�N����continue

		/* 
		�j�P�����G�H���C���覡��{�A���N�H�K�@�ӳ��I�J���A�A�bwhile�N��X���A
		�ái�X�ݡj��Ҧ��i���Q�X�ݹL�j���䵲�I�A�B�N�����䵲�I���V�����I�J�� �A
		���ƤW�z�B�J�A�Y�i�N�䤤�@�ӳs�q���q�M������
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

//for test�G
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
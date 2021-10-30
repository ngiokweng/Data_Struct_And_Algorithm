#include <iostream>
using namespace std;

#define MaxInt 32767  //��ܷ��j�ȡA�Y�L�a
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
int LocateVex(ALGraph G,VerTexType target) {
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

//2 1 A B A B
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
	return 0;
}
#include <iostream>
using namespace std;

#define MaxInt 32767  //��ܷ��j�ȡA�Y�L�a
#define MVNum 100  //�̤j���I��
typedef char VerTexType;  //�]���I���ƾ�������char
typedef int ArcType;   //�]�䪺�v���������㫬


struct AMGraph {  //Adjacency Matrix Graph �F���x�}��
	VerTexType vexs[MVNum];  //���I��
	ArcType arcs[MVNum][MVNum];  //�F���x�}
	int vexNum, arcNum;  //�Ϸ�e�����I�ƩM���
};

//��^target�b���I��������
int LocateVex(AMGraph G,VerTexType target) {
	for (int i = 0; i < G.vexNum; i++) {
		if (G.vexs[i] == target)return i;
	}
	return -1;
}

//�ЫصL�V��
void CreateUDG(AMGraph& G) {
	cin >> G.vexNum >> G.arcNum; //��J���I�ơB���
	
	//��J���I
	for (int i = 0; i < G.vexNum; i++)
		cin >> G.vexs[i]; 

	//��l�ƾF���x�}���C�@�ӭȬ�MaxInt
	for (int i = 0; i < G.vexNum; i++)
		for (int j = 0; j < G.vexNum; j++)
			G.arcs[i][j] = MaxInt;

	for (int k = 0; k < G.arcNum; k++) {
		VerTexType vex1, vex2;
		int i, j,w;
		cin >> vex1 >> vex2;  //��J�i��j�ҳs�����⳻�I
		cin >> w;  //��J�v��
		i = LocateVex(G, vex1);
		j = LocateVex(G, vex2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];  //�]���O��ٯx�}
	}

}
//test data�G3 2 A B C A B 1 A C 2
int main() {
	AMGraph G;
	CreateUDG(G);
	for (int i = 0; i < G.vexNum; i++) {
		for (int j = 0; j < G.vexNum; j++) {
			cout << G.arcs[i][j]<<" ";
		}
		cout << endl;
	}
		
	return 0;
}
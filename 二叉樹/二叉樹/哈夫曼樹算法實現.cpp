#include <iostream>
using namespace std;

//�ϥζ��Ǧs�x
typedef struct HTNode {
	int weight;  
	int lchild, rchild, parent;
}*HuffmanTree;

//�Hs1,s2��^���weight�̤p���`�I������
void select(HuffmanTree H,int n, int& s1, int& s2) {
	
	s1 = 0;
	s2 = 0;

	//���H�K��@��parent��0���`�I������
	for (int i = 1; i < n; i++) {
		if (H[i].parent == 0) {
			s1 = i;
			break;
		}
	}

	//�M�����X�Ĥ@�ӳ̤p
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

	//�A��X�ĤG�ӳ̤p
	for (int i = 1; i < n; i++) {
		if (H[i].parent == 0 && i != s1) {
			if (H[i].weight < H[s2].weight) {
				s2 = i;
				break;
			}
		}
	}
}

//���ҰҾ�c�y��k
void CreateHuffmanTree(HuffmanTree& H, int n) {
	///////////////////// ��l�ƪ��L�{ /////////////////////
	if (n <= 1)return;
	int m = 2 * n - 1;  //�Ʋզ@��2n - 1�Ӥ���
	H = new HTNode[m+1];  //0���U�Ф��ΡAH[m]��ܮڵ��I
	for (int i = 1; i <= m; i++) {
		H[i].lchild = 0;
		H[i].rchild = 0;
		H[i].parent = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> H[i].weight;
	}

	///////////////////// �����{ /////////////////////
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


//���Ұҽs�X��k
typedef char** HuffmanCode;
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode& HC,int n) {
	//�q���l��ڰf�V�D�C�Ӧr�Ū����Ұҽs�X�A�s�x�b�s�X��HC��
	HC = new char* [n + 1];   //���tn�Ӧr�Žs�X���Y���w�ڶq
	char* cd = new char[n];   //���t�{�ɦs��s�X���ʺA�Ʋ�
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		
		while (f != 0) {    //�q���l���I�}�l�V�W�^���A����ڵ��I
			--start;   //�^���@��start�V�e���@�Ӧ�m
			if (HT[f].lchild == c) {
				cd[start] = '0';    //���Ic�Of�����Ĥl�A�h�ͦ��N�X0
			}
			else {
				cd[start] = '1';   //���Ic�Of���k�Ĥl�A�h�ͦ��N�X1
			}
			c = f; f = HT[f].parent;  //�~��V�W�^���A����V���i�Ӧr�Ū��s�X
		}
		HC[i] = new char[n - start];   //����i�Ӧr�Ŧ�s�X���t�Ŷ�
		strcpy_s(HC[i], n - start,&cd[start]);   //�N�D�o���s�X�q�{�ɪŶ�cd�ƻs��HC����e�椤
	}
	delete[] cd;
}
int main() {
	/********************�i�ܨҡj���ҰҾ�c�y��k (�ܨҿ�J1 3 7 8) **********************/
	HuffmanTree H = NULL;
	int n = 4;
	CreateHuffmanTree(H, n);
	for (int i = 1; i <= n*2-1; i++) {
		cout << H[i].weight << " ";
	}
	cout << endl;
	cout << endl;

	/********************�i�ܨҡj���Ұҽs�X��k **********************/
	for (int i = 1; i <= n; i++) {
		cout << H[i].weight << " ";
	}
	cout <<"���������Ұҽs�X���G" << endl;
	HuffmanCode HC = NULL;
	CreateHuffmanCode(H, HC, n);
	for (int i = 1; i <= n; i++) {
		cout << HC[i] << " ";
	}
	
	delete[] H;
	delete[] HC;
}
#include <iostream>
using namespace std;

//��Ƶ��G���A�N�X
#define OVERFLOW -2

//�G�e���
typedef struct BiNode {
	char data;
	BiNode* lchild, * rchild;  //���k�l��
}*BiTree;

//�Ϋe�ǹM���ЫؤG�e��
void CreateBiTree(BiTree& T) {
	char data;
	cin >> data;
	if (data == '#') {  // #��ܪž�
		T = NULL;
	}
	else {
		T = new BiNode;
		if (!T)exit(OVERFLOW);

		T->data = data;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//�ƻs�G�e��
int Copy(BiTree T,BiTree& newTree) {
	if (!T) {
		newTree = NULL;
		return 0;
	}
	newTree = new BiNode;
	newTree->data = T->data;
	Copy(T->lchild, newTree->lchild);
	Copy(T->rchild, newTree->rchild);
	return 1;
}

//�p��`��
int deepth(BiTree T) {
	if (!T)return 0;
	int m = deepth(T->lchild);
	int n = deepth(T->rchild);
	if (m > n)
		return m + 1;
	else 
		return n + 1;
}

//�p�⵲�I��
int CountNode(BiTree T) {
	if (!T)return 0;
	return CountNode(T->lchild) + CountNode(T->rchild) + 1;
}

//�p�⸭�l��
int CountLeaf(BiTree T) {
	if (!T)return 0;
	if (!T->lchild && !T->rchild)return 1;
	return CountLeaf(T->lchild) + CountLeaf(T->rchild);
}
int main() {
	BiTree T;
	CreateBiTree(T);
	cout <<"�`�׬��G" << deepth(T) << endl;
	cout << "���I�Ƭ��G" << CountNode(T) << endl;
	cout << "���l�Ƭ��G" << CountLeaf(T) << endl;
	return 0;
}
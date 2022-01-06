#include <iostream>
using namespace std;

typedef int KeyType;
typedef int OtherInfo;

struct ElemType {
	KeyType key;    
	OtherInfo other;
};

typedef struct BSTNode {
	ElemType data;
	BSTNode* lchild,*rchild;
}*BSTree;

//�G�αƧǾ𪺬d��
BSTree	 SearchBST(BSTree T, KeyType key) {
	if ((!T) || T->data.key == key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);

}

//�V�G�αƧǾ𴡤J���I
void InsertBTSNode(BSTree&T,BSTree insNode) {
	if (!T) {
		T = insNode;
	}
	else if (insNode->data.key < T->data.key) {
		InsertBTSNode(T->lchild, insNode);
	}
	else {
		InsertBTSNode(T->rchild, insNode);
	}
}

//�ͦ��G�e�ƧǾ�(Binary Sort Tree)
void CreateBST(BSTree& T,int num) {
	for (int i = 0; i < num; i++) {
		cout << "�п�J��" << i + 1 << "�ӼƾڡG";
		BSTree tmp = new BSTNode;
		cin >> tmp->data.key;
		tmp->rchild = NULL;
		tmp->lchild = NULL;
		InsertBTSNode(T, tmp);
	}
}

//���ǹM��
void TraverseTree(BSTree T) {
	if (!T) {
		return;
	}
	TraverseTree(T->lchild);
	cout << T->data.key << " ";
	TraverseTree(T->rchild);
}


int main() {
	BSTree tree = NULL;
	CreateBST(tree, 5);
	TraverseTree(tree);

	return 0;
}
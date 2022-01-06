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

//二及排序樹的查找
BSTree	 SearchBST(BSTree T, KeyType key) {
	if ((!T) || T->data.key == key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);

}

//向二及排序樹插入結點
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

//生成二叉排序樹(Binary Sort Tree)
void CreateBST(BSTree& T,int num) {
	for (int i = 0; i < num; i++) {
		cout << "請輸入第" << i + 1 << "個數據：";
		BSTree tmp = new BSTNode;
		cin >> tmp->data.key;
		tmp->rchild = NULL;
		tmp->lchild = NULL;
		InsertBTSNode(T, tmp);
	}
}

//中序遍歷
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
#include <iostream>
using namespace std;

//函數結果狀態代碼
#define OVERFLOW -2

//二叉鏈表
typedef struct BiNode {
	char data;
	BiNode* lchild, * rchild;  //左右子樹
}*BiTree;

//用前序遍歷創建二叉樹
void CreateBiTree(BiTree& T) {
	char data;
	cin >> data;
	if (data == '#') {  // #表示空樹
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

//複製二叉樹
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

//計算深度
int deepth(BiTree T) {
	if (!T)return 0;
	int m = deepth(T->lchild);
	int n = deepth(T->rchild);
	if (m > n)
		return m + 1;
	else 
		return n + 1;
}

//計算結點數
int CountNode(BiTree T) {
	if (!T)return 0;
	return CountNode(T->lchild) + CountNode(T->rchild) + 1;
}

//計算葉子數
int CountLeaf(BiTree T) {
	if (!T)return 0;
	if (!T->lchild && !T->rchild)return 1;
	return CountLeaf(T->lchild) + CountLeaf(T->rchild);
}
int main() {
	BiTree T;
	CreateBiTree(T);
	cout <<"深度為：" << deepth(T) << endl;
	cout << "結點數為：" << CountNode(T) << endl;
	cout << "葉子數為：" << CountLeaf(T) << endl;
	return 0;
}
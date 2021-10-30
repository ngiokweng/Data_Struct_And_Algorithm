#include <iostream>
using namespace std;

//�G�e���
typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;  //���k�l��
}*BiTree;

//�e�ǹM�� ( ��->��->�k )
void PreOrderTraverse(BiTree T) {
	if (!T)return;
	cout << T->data<<" ";
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//���ǹM��( ��->��->�k )
void InOrderTraverse(BiTree T) {
	if (!T)return;
	InOrderTraverse(T->lchild);
	cout << T->data << " ";
	InOrderTraverse(T->rchild);
}

//��ǹM��( ��->�k->�� )
void PostOrderTraverse(BiTree T) {
	if (!T)return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data << " ";
}

//�D���k�����ǹM��
#include <stack>
void InOrderTraverse_2(BiTree T) {
	BiTree p = T;
	BiTree q;
	stack<BiTree> s;
	while (p || !s.empty()){
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			q = s.top();
			s.pop();
			cout << q->data << " ";
			p = q->rchild;
		}
	}
}

//�h�ǹM��
#include <queue>
void LevelOrder(BiTree T) {
	queue<BiTree> q;
	q.push(T);
	BiTree p;
	while (!q.empty()) {
		p = q.front();
		cout << p->data << " ";
		q.pop();
		if(p->lchild)q.push(p->lchild);
		if(p->rchild)q.push(p->rchild);
	}
}

int main() {
	//for test
	BiNode* Tree = new BiNode;
	Tree->data = 1;
	Tree->lchild = new BiNode;
	Tree->lchild->data = 2;
	Tree->lchild->lchild = new BiNode;
	Tree->lchild->rchild = new BiNode;
	Tree->lchild->lchild->data = 4;
	Tree->lchild->lchild->lchild = NULL;
	Tree->lchild->lchild->rchild = NULL;
	Tree->lchild->rchild->data = 5;
	Tree->lchild->rchild->lchild = NULL;
	Tree->lchild->rchild->rchild = NULL;

	Tree->rchild = new BiNode;
	Tree->rchild->data = 3;
	Tree->rchild->lchild = NULL;
	Tree->rchild->rchild = NULL;


	//PreOrderTraverse(Tree);
	//InOrderTraverse(Tree);  
	//PostOrderTraverse(Tree);
	//InOrderTraverse_2(Tree);
	LevelOrder(Tree);
	return 0;
}
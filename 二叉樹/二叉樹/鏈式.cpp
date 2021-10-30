//二叉鏈表
typedef struct BiNode {
	int data;
	BiNode* lchild, * rchild;  //左右子樹
}*BiTree;

//三叉鏈表
typedef struct TriTNode {
	int data;
	TriTNode* lchild, * rchild,*parent;  //左右子樹、雙親結點
}*TriTree;
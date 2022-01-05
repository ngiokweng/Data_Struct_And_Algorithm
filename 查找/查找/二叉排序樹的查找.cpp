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
	BSTree lchild,rchild;
}*BSTree;

BSTree	 SearchBST(BSTree T, KeyType key) {
	if ((!T) || T->data.key == key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);

}
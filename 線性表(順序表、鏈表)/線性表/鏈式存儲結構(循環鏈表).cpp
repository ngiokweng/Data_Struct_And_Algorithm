#include <iostream>
#include <string>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

typedef struct LNode {
	ElemType data;
	LNode* next;
}*LinkList;

//帶尾指針循環鏈表的合並
LinkList Connect(LinkList Ta, LinkList Tb) {  //Ta是鏈表a的尾指針，Tb同理
	LinkList p = Ta->next;  //保存Ta->next，即頭結點
	Ta->next = Tb->next->next;
	delete Tb->next;  //刪除Tb頭結點( Tb是最後，Tb->next就是頭結點 )
	Tb->next = p;
	
	return Tb;
}

int main() {}
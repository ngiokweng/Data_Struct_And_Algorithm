#include <iostream>
#include <string>
using namespace std;

//��Ƶ��G���A�N�X
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

//�a�����w�`������X��
LinkList Connect(LinkList Ta, LinkList Tb) {  //Ta�O���a�������w�ATb�P�z
	LinkList p = Ta->next;  //�O�sTa->next�A�Y�Y���I
	Ta->next = Tb->next->next;
	delete Tb->next;  //�R��Tb�Y���I( Tb�O�̫�ATb->next�N�O�Y���I )
	Tb->next = p;
	
	return Tb;
}

int main() {}
#include <iostream>
using namespace std;

//��Ƶ��G���A�N�X
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�O������� ��ȬO��Ƶ��G���A�N�X
typedef int Status;
typedef char ElemType;

#define MAXSIZE 1000

struct SqList {
	ElemType* elem;
	int length;
};

//��l�ƽu�ʪ�
Status InitList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	return OK;
}

//�P���w�s�b���u�ʪ�
void DestroyList(SqList& L) {
	if(L.elem)delete[] L.elem;
}

//�M�Žu�ʪ�
void ClearList(SqList& L) {
	L.length = 0;
}

//�ˬd�u�ʪ�O�_����
Status IsEmpty(SqList L) {
	if (L.length)return FALSE;
	return TRUE;
}

//��^�u�ʪ����
int ListLength(SqList L) {
	return L.length;
}

//�N�u�ʪ��i�Ӥ�����^��e
Status GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length)return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//�b�u��L���i�Ӧ�m���Je
Status ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length+1)return ERROR;
	if(L.length == MAXSIZE)return ERROR;
	for (int index = L.length - 1; index >= i-1; index--) {
		L.elem[index + 1] = L.elem[index];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

//�R���u�ʪ�L��i�Ӥ���
Status ListDelete(SqList& L,int i) {
	if (i<1 || i>L.length)return ERROR;
	for (int index = i - 1; index < L.length-1; index++) {
		L.elem[index] = L.elem[index + 1];
	}
	L.length--;
	return OK;
}

//�d��Pe�ۦP�������A����^�Ǹ��A�䤣���^0
Status LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)return i + 1;
	}
	return 0;
}

int main() {

	return 0;
}
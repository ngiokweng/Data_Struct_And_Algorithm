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

#define MAXSIZE 100

typedef string ElemType;
typedef int Status;

struct SqStack {
	ElemType* top;
	ElemType* base;
	int stacksize;
};

Status InitStack(SqStack& S) {
	S.base = new ElemType[MAXSIZE];
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status DestroyStack(SqStack& S) {
	if (S.base) {
		delete[] S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//�J��
Status Push(SqStack& S, ElemType e) {
	if (S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}

//�X��
Status Pop(SqStack& S, ElemType& e) {
	if (S.base == S.top) return ERROR;
	e = *--S.top;
	return OK;
}
//���o�̳�����
Status GetTop(SqStack S,ElemType& e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}
//��^�̪�
int StackLength(SqStack S) {
	return S.top - S.base;
}


//�����F�� -> ����F��
string Change(SqStack S) {
	string str = "";   //�s���ecin�J���r��
	string res = "";   //�s�����F�������G
	string oper = "+-*/()";  //�n�s�i�̤����Ÿ�

	bool flag = false;  //�P�_�O�n�s�i�̤����Ÿ��A�٬O�@�몺�Ʀr

	while (1) {
		cin >> str;
		if (str == "end")break;  //��Jend��A���������F������J

		//�P�_�O�n�s�i�̤����Ÿ��A�٬O�@�몺�Ʀr
		for (int i = 0; i < oper.length(); i++) {
			if (str[0] == oper[i]) {
				//�O�B��ŮɡAflag��true
				flag = true;
				break;
			}
		}

		//�O�B��Ū����p
		if (flag) {
			ElemType topElem;
			GetTop(S, topElem);

			string e = "";

			if (str == ")") {   // ��e�Ÿ��O�i)�j �ɡA�n�N�̤��i(�j�Ÿ��e���Ҧ��Ÿ�Pop�X ( �i( �j�Ÿ��b����F��������{ )
				while (Pop(S, e) != ERROR && e != "("){  
					res += e + " ";
				}
			}
			else if ((topElem == "*" || topElem == "/") &&  //��̳��Ÿ����u���Ű����e�Ÿ���
				(str == "+" || str == "-")) {						
				while (Pop(S, e) != ERROR) {  //�n�N�̤��Ҧ��Ÿ�Pop�X
					res += e + " ";
				}
				Push(S, str);   //�A�N��e�Ÿ�Push�J

			}
			else {
				Push(S,	str);  //��L���p�N����Push�J
			}

		}

		//���O�B��Ū����p
		if (!flag) {
			res += str + " ";
		}
		flag = false;
	}

	//�Y�̤��٦��Ÿ��A�nPop�z�b
	string e = "";
	while (Pop(S, e) != ERROR) {
		res += e + " ";
	}
	
	//��^�ഫ�᪺ �i����F���j
	return res;
}

//�p��̳�����Ӥ���
double CalcTwoElem(SqStack& S,char oper) {
	ElemType e1, e2;
	Pop(S, e1);
	Pop(S, e2);

	double v1 = stod(e1), v2 = stod(e2);
	switch (oper)
	{
	case '+':
		return v2 + v1;
	case '-':
		return v2 - v1;
	case '*':
		return v2 * v1;
	case '/':
		return v2 / v1;
	}
	return 0;
}


//�|�h�B��
/*
* �W�h�G�q����k�M����F�����Ʀr�M�Ÿ��A�J��Ʀr�N�i���G�A
	�J��Ÿ��A�N�N���̳���ӼƦr�X�̡A�i��ާ@�A��i�̡A�@���� �̲���o���G�C
*/
void PrintCalcResult(SqStack& S,string str) {
	string oper = "+-*/";
	string tmp = "";
	int j = 0;
	for (int i = 0; i < str.length(); i++) {	
		while (str[j] != ' ') {
			tmp += str[j++];
		}

		if (tmp[0] != '+' && tmp[0] != '-' && tmp[0] != '*' && tmp[0] != '/') {
			Push(S, tmp);
		}
		else {

			ElemType e = to_string(CalcTwoElem(S, tmp[0]));
			cout << "CalcTwoElem : " << e << endl;
			Push(S, e);
		}

		tmp = "";
		j++;
		i = j;
	}

	//�g�W�z�p�⧹��A�̸̳ѤU�����ӴN�O����
	Pop(S, tmp);
	cout << "�̲׵��׬��G" <<tmp << endl;
}

int main() {
	SqStack S;
	InitStack(S);
	cout << "�п�J�@�����F���A�@��@�r�� ( ��Jend�N���J���� )�G" << endl;
	string str = Change(S);
	cout << "����F���G" << str << endl;
	PrintCalcResult(S, str);
	DestroyStack(S);
	return 0;
}
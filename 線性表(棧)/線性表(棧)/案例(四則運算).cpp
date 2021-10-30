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

//入棧
Status Push(SqStack& S, ElemType e) {
	if (S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}

//出棧
Status Pop(SqStack& S, ElemType& e) {
	if (S.base == S.top) return ERROR;
	e = *--S.top;
	return OK;
}
//取得棧頂元素
Status GetTop(SqStack S,ElemType& e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}
//返回棧長
int StackLength(SqStack S) {
	return S.top - S.base;
}


//中綴表達式 -> 後綴表達式
string Change(SqStack S) {
	string str = "";   //存放當前cin入的字串
	string res = "";   //存放後綴表達式的結果
	string oper = "+-*/()";  //要存進棧中的符號

	bool flag = false;  //判斷是要存進棧中的符號，還是一般的數字

	while (1) {
		cin >> str;
		if (str == "end")break;  //輸入end後，結束中綴表達式的輸入

		//判斷是要存進棧中的符號，還是一般的數字
		for (int i = 0; i < oper.length(); i++) {
			if (str[0] == oper[i]) {
				//是運算符時，flag為true
				flag = true;
				break;
			}
		}

		//是運算符的情況
		if (flag) {
			ElemType topElem;
			GetTop(S, topElem);

			string e = "";

			if (str == ")") {   // 當前符號是【)】 時，要將棧中【(】符號前的所有符號Pop出 ( 【( 】符號在後綴表達式中不顯現 )
				while (Pop(S, e) != ERROR && e != "("){  
					res += e + " ";
				}
			}
			else if ((topElem == "*" || topElem == "/") &&  //當棧頂符號的優先級高於當前符號時
				(str == "+" || str == "-")) {						
				while (Pop(S, e) != ERROR) {  //要將棧中所有符號Pop出
					res += e + " ";
				}
				Push(S, str);   //再將當前符號Push入

			}
			else {
				Push(S,	str);  //其他情況就直接Push入
			}

		}

		//不是運算符的情況
		if (!flag) {
			res += str + " ";
		}
		flag = false;
	}

	//若棧中還有符號，要Pop干淨
	string e = "";
	while (Pop(S, e) != ERROR) {
		res += e + " ";
	}
	
	//返回轉換後的 【後綴表達式】
	return res;
}

//計算棧頂的兩個元素
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


//四則運算
/*
* 規則：從左到右遍歷表達式的數字和符號，遇到數字就進結果，
	遇到符號，就將等棧頂兩個數字出棧，進行操作，行進棧，一直到 最終獲得結果。
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

	//經上述計算完後，棧裡剩下的那個就是答覆
	Pop(S, tmp);
	cout << "最終答案為：" <<tmp << endl;
}

int main() {
	SqStack S;
	InitStack(S);
	cout << "請輸入一中綴表達式，一行一字元 ( 輸入end代表輸入完成 )：" << endl;
	string str = Change(S);
	cout << "後綴表達式：" << str << endl;
	PrintCalcResult(S, str);
	DestroyStack(S);
	return 0;
}
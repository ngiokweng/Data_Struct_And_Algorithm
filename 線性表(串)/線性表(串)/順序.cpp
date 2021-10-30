#include <iostream>
using namespace std;

//函數結果狀態代碼
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

#define MAXLEN 255

struct SString {
	char ch[MAXLEN + 1];  //通常不用下標為0那格( 所以由1開始 )，為方便一些算法
	int length;  //串的當前長度
};



//字符串長度
int StrLength(SString S) {
	return S.length;
}

//打印字符串
void PrintString(SString S) {
	for (int i = 1; i <= StrLength(S); i++) {
		cout << S.ch[i];
	}
	cout << endl;
}
//字符串比較
int StrCompare(SString S,SString T) {
	int len = min(StrLength(S), StrLength(T));
	for (int i = 1; i <= len; i++) {
		if (S.ch[i] > T.ch[i]) {
			return 1;
		}
		else if (S.ch[i] < T.ch[i]) {
			return -1;
		}
	}
	if (StrLength(S) == StrLength(T)) {
		return 0;
	}
	return StrLength(S) > StrLength(T) ? 1 : -1;
}

//截取字串
void SubString(SString& Sub, SString S, int pos, int len) {
	/*
	串S存在，1≤pos≤StrLength(S)，
	且0≤len≤StrLength(S)-pos+1，用Sub返
	回串S的第pos個字符起長度為len的子串。
	*/
	if (pos<1 || pos>StrLength(S))return;
	if (len<0 || len>StrLength(S) - pos + 1)return;

	Sub.length = 0;
	for (int i = 1; i <= len; i++) {
		Sub.ch[i] = S.ch[i + pos - 1];
		Sub.length++;
	}
}

/////字符匹配，返回索引( 我的寫法 )
//int Index(SString S, SString T,int pos) {
//	/*
//	串S和T存在，T是非空串，1≤pos≤StrLength(S)。
//	若主串S中存在和串T值相同的子串，則返回它在主串S中
//	第pos個字符之後第一次出現的位置，否則返回0。
//	*/
//	int index = 0;
//	for (int i = pos; i < StrLength(S); i++) {
//		index = i;
//		for (int j = 1; j <= StrLength(T); j++) {
//			if (S.ch[i + j - 1] != T.ch[j]) {
//				index = 0;
//				break;
//			}
//		}
//		if (index)return index;
//	}
//	return 0;
//}
//字符匹配，返回索引( 《大話數據結構》寫法 )
int Index(SString S, SString T, int pos)
{
	int n, m, i;
	SString sub;
	if (pos > 0)
	{
		/* 得到主串S的长度 */
		n = StrLength(S);
		/* 得到子串T的长度 */
		m = StrLength(T);
		i = pos;
		while (i <= n - m + 1)
		{
			/* 取主串第i个位置 */
			/* 长度与T相等子串给sub */
			SubString(sub, S, i, m);
			/* 如果两串不相等 */
			if (StrCompare(sub, T) != 0)
				++i;
			/* 如果两串相等 */
			else
				/* 则返回i值 */
				return i;
		}
	}
	/* 若无子串与T相等，返回0 */
	return 0;
}

//字符匹配，返回索引 ( BF暴力破解法)
int Index_BF(SString S, SString T, int pos) {
	int i = pos, j = 1;
	while (i <= StrLength(S) && j <= StrLength(T)) {
		if (S.ch[i++] != T.ch[j++]) {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j == StrLength(T)+1)return i - j + 1;
	return 0;
}

int main() {
	//for test
	SString s1, s2;
	s1.length = s2.length = 0;
	char test[] = "abcdefghijklmnopqz";
	for (int i = 1; i < 11; i++) {
		s1.ch[i] = test[i-1];
		s1.length++;
	}
	for (int i = 1; i < 4; i++) {
		s2.ch[i] = test[i + 2];
		s2.length++;
	}
	PrintString(s1);
	PrintString(s2);
	cout << "Index(大話數據結構》寫法) : " << Index(s1, s2, 4) << endl;
	cout << "Index_BF() : " << Index_BF(s1, s2, 4) << endl;
	return 0;
}
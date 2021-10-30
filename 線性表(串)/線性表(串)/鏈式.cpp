#include <iostream>
using namespace std;

#define CHUNKSIZE 80

struct Chunk {
	char ch[CHUNKSIZE];
	Chunk* next;
};

struct LString {
	Chunk* head, * tail; //串的頭、尾指針
	int curlen;	//串的當前長度
};

int main() {
	return 0;
}
#include <iostream>
using namespace std;

#define CHUNKSIZE 80

struct Chunk {
	char ch[CHUNKSIZE];
	Chunk* next;
};

struct LString {
	Chunk* head, * tail; //�ꪺ�Y�B�����w
	int curlen;	//�ꪺ��e����
};

int main() {
	return 0;
}
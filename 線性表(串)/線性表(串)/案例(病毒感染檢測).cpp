#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//視頻：https://www.bilibili.com/video/BV1nJ411V7bd?p=75&spm_id_from=pageDriver
int main() {
	string sourceStr[4] = { "bbaabbba","aaabbbba","abceaabb","abaabcea"};
	string targetStr[4] = { "baa","baa","aabb","aabb" };
	string resStr[4] = {};
	bool flag = true;
	for (int i = 0; i < sizeof(sourceStr) / sizeof(sourceStr[0]); i++) {
		string tmp = targetStr[i] + targetStr[i];  
		string searchStr = "";
		for (int j = 0; j < targetStr[i].length(); j++) {
			searchStr = tmp.substr(j, targetStr[i].length());  
			if (sourceStr[i].find(searchStr) != string::npos) {
				resStr[i] = "YES";
				break;
			}
			else if (j == targetStr[i].length() - 1) {
				resStr[i] = "NO";
			}
		}
	}

	//輸出到外部文件中儲存
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	for (int i = 0; i < sizeof(resStr) / sizeof(resStr[0]); i++) {
		ofs << targetStr[i] << "\t" << sourceStr[i] << "\t" << resStr[i] << endl;
	}
	ofs.close();
	

	return 0;
}
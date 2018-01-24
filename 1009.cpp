#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main()
{
	char rawStr[81];
	for (int i = 0; i < 81; i++)
		rawStr[i] = 'a';
	cin.getline(rawStr, 81);
	int spaceSign = 81, endSign = 81;
	for (int i = 80; i >= 0; i--) {
		if (spaceSign == 81 && endSign == 81) {
			if (rawStr[i] == '\0') endSign = i;
			continue;
		}
		if (spaceSign == 81 && i == 0 && endSign < 81) {
			if (rawStr[i] == '\0') return 0;
			cout << rawStr;
			return 0;
		}
		if (rawStr[i] == ' ') {
			spaceSign = i;
			if (spaceSign < endSign) {
				for (int j = spaceSign + 1; j < endSign; j++) {
					cout << rawStr[j];
				}
				cout << ' ';
				endSign = spaceSign;
				}
			}
		if (i == 0) {
			for (int k = 0; k < endSign; k++)
				cout << rawStr[k];
		}
			
	}

	system("pause");
	return 0;
}

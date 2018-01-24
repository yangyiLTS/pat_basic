#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {

	char rawstr[10000];
	int eflag, zhishu;
	cin >> rawstr;
	for (int i = 0; rawstr[i] != '\0'; i++) {
		if (rawstr[i] == 'E') {
			eflag = i;
			break;
		}
	}

	zhishu = rawstr[eflag + 2] - 48;
	for (int i = eflag + 3; rawstr[i] != '\0'; i++) {
		zhishu = zhishu * 10 + rawstr[i] - 48;
	}
	if (rawstr[eflag + 1] == '-')
		zhishu *= -1;
	if (rawstr[0] == '-') cout << '-';
	
	int xiaosu = 1 + zhishu;
	if (xiaosu <= 0) {
		for (int i = 0; i >= xiaosu; i--) {
			if (i == -1)
				cout << '.';
			cout << 0;
		}
		for (int i = 1; rawstr[i] != 'E'; i++) {
			if (i == 2) continue;
			cout << rawstr[i];
		}
	}
	else {
		int i = 1;
		int etmp = xiaosu;
		while (1) {
			if (rawstr[i] == '.') {
				i++; 
				continue;
			}
			if (rawstr[i] == 'E') {
				if (etmp > 0) {
					cout << 0;
					etmp--;
					continue;
				}
				else
					break;
			}
			if (etmp == 0) {
				cout << '.';
				while (rawstr[i] != 'E') {
					cout << rawstr[i];
					i++;
				}
				break;
			}
			cout << rawstr[i];
			i++;
			etmp--;
		}
	}

	system("pause");
	return 0;

}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

const char M[12] = "10X98765432";
const int R[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

bool idjuge(char *s) {
	int ans = 0;
	for (int i = 0; i < 17; i++) {
		if (*(s + i) == 'X') {
			return 0;
		}
		ans += (*(s + i) - 48) * R[i];
	}
	if (*(s + 17) == M[ans % 11]) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int flag = 0, n;
	char idnum[19];
	cin >> n;
	for (int i = 0; i < n; i++) {
		char idnum[19];
		cin >> idnum;
		int ans = idjuge(idnum);
		if (ans == 0) {
			flag++;
			cout << idnum << endl;
		}
	}
	if (flag == 0) {
		cout << "All passed";
	}
	system("pause");
	return 0;
}

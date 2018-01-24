#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int L[97] = { 0 };

bool isBroken(char c) {
	if (c > 96 && c < 123) {
		return L[c - 32];
	}
	else if (c > 64 && c < 91) {
		return L[c] && L['+'];
	}
	else {
		return L[c];
	}
}

int main() {
	char breakenKey[100010];
	char inputString[100010];
	cin.getline(breakenKey,100010);
	cin >> inputString;
	for (int i = 0; i < 97; i++) {
		L[i] = 1;
	}
	for (int i = 0; breakenKey[i] != '\0'; i++) {
		if (breakenKey[i] >= 'a'&&breakenKey[i] >= 'z') {
			L[breakenKey[i] - 32] = 0;
		}
		else {
			L[breakenKey[i]] = 0;
		}
	}

	for (int i = 0; inputString[i] != '\0'; i++) {
		if (isBroken(inputString[i])) {
			cout << inputString[i];
		}
	}
	cout << endl;
	system("pause");
	return 0;
}

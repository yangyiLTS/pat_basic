#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;


int main() {
	char s[10010];
	cin >> s;
	int ht[6] = { 0 };
	char pat[] = "PATest";
	for (int i = 0; s[i] != '\0'; i++) {
		for (int j = 0; j < 6; j++) {
			if (s[i] == pat[j]) {
				ht[j]++;
			}
		}
	}
	while (ht[0]+ ht[1] + ht[2] + ht[3] + ht[4] + ht[5]) {
		for (int i = 0; i < 6; i++) {
			if (ht[i] != 0) {
				cout << pat[i];
				ht[i]--;
			}
		}
	}

	system("pause");
	return 0;
}

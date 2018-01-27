#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
char L[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };

int main() {
	string A, B;
	cin >> A >> B;
	int alen, blen, diff;
	alen = A.length();
	blen = B.length();
	diff = blen - alen;
	char C[110];

	C[alen > blen? alen : blen] = '\0';
	if (blen >= alen) {
		for (int i = blen - 1; i >= 0; i--) {
			if ((i - diff) < 0) {
				C[i] = B[i];
				continue;
			}
			int a, b;
			b = int(B[i] - 48);
			a = int(A[i - diff] - 48);
			if ((blen + i) % 2 == 1) {
				C[i] = L[(a + b) % 13];
			}
			else {
				C[i] = char((b - a) < 0 ? (b - a + 10 + 48) : (b - a + 48));
			}
		}
	}
	else {
		for (int i = alen - 1; i >= 0; i--) {
			int a, b;
			a = int(A[i] - 48);
			if ((i + diff) < 0) {
				b = 0;
			}
			else {
				b = int(B[i + diff] - 48);
			}

			if ((alen + i) % 2 == 1) {
				C[i] = L[(a + b) % 13];
			}
			else {
				C[i] = char((b - a) < 0 ? (b - a + 10 + 48) : (b - a + 48));
			}
		}
	}
	cout << C;
	system("pause");
	return 0;
}

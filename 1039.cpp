#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main() {
	char a[1010];
	char b[1010];
	cin >> a >> b;
	int y = 0, q = 0;
	int A[100] = { 0 };
	int B[100] = { 0 };
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] >= '0'&&a[i] <= '9') {
			A[a[i] - 48]++;
		}
		else if (a[i] >= 'A'&&a[i] <= 'Z') {
			A[a[i] - 54]++;
		}
		else if (a[i] >= 'a'&&a[i] <= 'z') {
			A[a[i] - 59]++;
		}
	}
	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] >= '0'&&b[i] <= '9') {
			B[b[i] - 48]++;
		}
		else if (b[i] >= 'A'&&b[i] <= 'Z') {
			B[b[i] - 54]++;
		}
		else if (b[i] >= 'a'&&b[i] <= 'z') {
			B[b[i] - 59]++;
		}
	}
	for (int i = 0; i < 100; i++) {
		if ((A[i] - B[i]) >= 0) {
			y += (A[i] - B[i]);
		}
		else {
			q += (B[i] - A[i]);
		}
	}
	if (q == 0) {
		cout << "Yes " << y;
	}
	else {
		cout << "NO " << q;
	}
	system("pause");
	return 0;
}

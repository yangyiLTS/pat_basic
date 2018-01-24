#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;
	int a[100010] = { 0 };
	for (int i = 0; i < n; i++) {
		int school, s;
		cin >> school >> s;
		a[school] += s;
	}
	int q = 1, p = a[1];
	for (int i = 1; i < 100010; i++) {
		if (a[i] > p) {
			p = a[i];
			q = i;
		}
	}
	cout << q << ' ' << p;
	system("pause");
	return 0;
}

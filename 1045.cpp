#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;


int main() {
	int N;
	cin >> N;
	int L[100010], ans[100010];
	int leftMax[100010], rightMin[100010];
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}

	leftMax[0] = 0;
	for (int i = 1; i < N; i++) {
		if (L[i - 1] > leftMax[i - 1]) {
			leftMax[i] = L[i - 1];
		}
		else {
			leftMax[i] = leftMax[i - 1];
		}
	}

	rightMin[N - 1] = 0x3fffffff;
	for (int i = N - 2; i >= 0; i--) {
		if (L[i + 1] < rightMin[i + 1]) {
			rightMin[i] = L[i + 1];
		}
		else {
			rightMin[i] = rightMin[i + 1];
		}
	}

	for (int i = 0; i < N; i++) {
		if (L[i] > leftMax[i] && L[i] < rightMin[i]) {
			ans[count++] = L[i];
		}
	}
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		if (i) {
			cout << ' ';
		}
		cout << ans[i];
	}
	cout << endl;
	system("pause");
	return 0;
}

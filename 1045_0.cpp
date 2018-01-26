#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
// 暴力解法 不好使不好使

int main() {
	int N;
	cin >> N;
	int L[100010] = { 0 };
	int L2[100010];
	for (int i = 0; i < N; i++) {
		cin >> L[i];
		L2[i] = L[i];
	}
	sort(L, L + N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (L[i] == L2[i]) {
			count++;
		}
		else {
			L[i] = 0;
		}
	}
	cout << count << endl;
	count = 0;
	for (int i = 0; i < N; i++) {

		if (L[i]) {
			if (count)
				cout << ' ';
			cout << L[i];
			count = 1;
		}
    }
    cout << endl;

	system("pause");
	return 0;
}

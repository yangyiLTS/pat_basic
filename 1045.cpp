#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

// 就知道会超时

int partition(const int L[], int N, int pivo) {
	int flag = 1;
	int low = 0, high = N - 1;
	while (flag && low < pivo) {
		if (L[low] > L[pivo]) {
			flag = 0;
		}
		low++;
	}
	while (flag && high > pivo) {
		if (L[high] < L[pivo]) {
			flag = 0;
		}
		high--;
	}
	return flag;
}

int main() {
	int N;
	cin >> N;
	int L[100010], L2[100010];
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < N; i++) {
		if (partition(L, N, i)) {
			L2[count++] = L[i];
		}
	}
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		if (i != 0) {
			cout << ' ';
		}
		cout << L2[i];
	}

	system("pause");
	return 0;
}

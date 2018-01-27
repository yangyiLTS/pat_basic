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
	double L[100010];
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += L[i] * ((double)N - (double)i) * ((double)i + 1.0);
	}

	printf("%0.2f", sum);
	system("pause");
	return 0;
}

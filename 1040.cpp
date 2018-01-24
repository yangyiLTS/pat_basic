#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
	char S[100010];
	//int P[100010] = { 0 };
	//int A[100010] = { 0 };
	int P[100010] = { 0 };
	cin >> S;
	int pcount = 0, end = 0;
	for (; S[end] != '\0'; end++) {
		if (S[end] == 'P') {
			P[end] = ++pcount;
		}
		else {
			P[end] = pcount;
		}
	}
	ll sum = 0;
	int rt = 0;
	for (int i = end; i >= 0; i--) {
		if (S[i] == 'A') {
			sum += rt*P[i];
		}
		else if (S[i] == 'T') {
			rt++;
		}
	}

	cout << (ll)sum % 1000000007;

	system("pause");
	return 0;
}

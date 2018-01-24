#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int s[101] = { 0 };
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s[a]++;
	}
	
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		cout << s[a];
		if (i != k - 1) {
			cout << ' ';
		}
	}

	system("pause");
	return 0;
}

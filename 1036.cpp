#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;



int main() {
	int n;
	char s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cout << s;
	}
	cout << endl;
	for (int i = 0; i < n / 2 + n % 2 - 2; i++) {
		cout << s;
		for (int i = 0; i < n - 2; i++) {
			cout << ' ';
		}
		cout << s << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << s;
	}

	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	int n;
	char c;
	cin >> n >> c;
	int count = 0;
	int a = 1;
	n++;
	while (n >= 2 * a) {
		n -= 2 * a;
		a += 2;
		count++;
	}
	int max = 2 * count - 1;
	for (int i = count; i > 0; i--) {
		for (int j = 0; j < (max - (2 * i - 1)) / 2; j++)
			cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++)
			cout << c;
		cout << endl;
	}

	for (int i = 2; i <= count; i++) {
		for (int j = 0; j < (max - (2 * i - 1)) / 2; j++)
			cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++)
			cout << c;
		cout << endl;
	}
	cout << n;
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int getP(int a, int d);

int main() {

	char a[20], b[20];
	int da, db;
	cin >> a >> da >> b >> db;
	int acount = 0, bcount = 0;
	for (int i = 0; i < 20; i++) {
		if (a[i] - 48 == da) acount++;
		if (a[i] == '\0') break;
	}

	for (int i = 0; i < 20; i++) {
		if (b[i] - 48 == db) bcount++;
		if (b[i] == '\0') break;
	}

	cout << getP(acount, da) + getP(bcount, db);

	system("pause");
	return 0;
}

int getP(int a, int d) {
	if (a == 0) return 0;
	int sum = 0;
	for (int i = 0; i < a; i++) {
		sum += d;
		d *= 10;
	}
	return sum;
}
//完美 还是0ms
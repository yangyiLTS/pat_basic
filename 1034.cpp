#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}// 求a与b的最大公约数

struct Fraction {
	ll up, down;
};

Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0) {
		result.down = 1;
	}
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up*b.down + a.down*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}

Fraction minu(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up*b.down - b.up*a.down;
	result.down = a.down*b.down;
	return reduction(result);
}

Fraction multi(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}

Fraction divide(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up*b.down;
	result.down = b.up*a.down;
	return reduction(result);
}

void showResult(Fraction r) {
	r = reduction(r);
	if (r.up < 0) {
		cout << '(';
	}
	if (r.down == 1) {
		cout << r.up;
	}
	else if (abs(r.up) > r.down) {
		cout << r.up / r.down << ' ' << abs(r.up) % r.down << '/' << r.down;
	}
	else {
		cout << r.up << '/' << r.down;
	}
	if (r.up < 0) {
		cout << ')';
	}
}

int main() {
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	// 加法
	showResult(a);
	cout << " + ";
	showResult(b);
	cout << " = ";
	showResult(add(a, b));
	cout << endl;

	//减法
	showResult(a);
	cout << " - ";
	showResult(b);
	cout << " = ";
	showResult(minu(a, b));
	cout << endl;

	//乘法
	showResult(a);
	cout << " * ";
	showResult(b);
	cout << " = ";
	showResult(multi(a, b));
	cout << endl;

	//除法
	showResult(a);
	cout << " / ";
	showResult(b);
	cout << " = ";
	if (b.up == 0) {
		cout << "Inf";
	}
	else {
		showResult(divide(a, b));
	}
	cout << endl;

	system("pause");
	return 0;
}

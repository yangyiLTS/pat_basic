#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct money {
	int g, s, k;
};

void reduction(money a) {
	int sum = a.g * 17 * 29 + a.s * 29 + a.k;
	if (sum < 0) {
		sum *= -1;
		cout << '-';
	}
	cout << sum / 493 << '.' << (sum % 493) / 29 << '.' << (sum % 493) % 29;
	return;
}

int main() {
	money p, a;
	scanf("%d.%d.%d %d.%d.%d", &p.g, &p.s, &p.k, &a.g, &a.s, &a.k);
	money r;
	r.g = a.g - p.g;
	r.s = a.s - p.s;
	r.k = a.k - p.k;
	reduction(r);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	int c1, c2;
	cin >> c1 >> c2;
	double time = double(c2 - c1) / 100;
	double s = time - int(time / 60) * 60;
	int m, h;
	m = int(time) / 60 % 60;
	h = int(time) / 3600;
	printf("%02d:%02d:%02.0f", h, m, s);
	system("pause");
	return 0;
}

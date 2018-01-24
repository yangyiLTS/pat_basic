#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {

	int A, B, C, D;
	cin >> A >> B >> D;
	C = A + B;
	int out[32] = { 0 };
	int count = 0;
	while (1) {
		out[count] = C%D;
		C /= D;
		count++;
		if (C == 0) break;
	}

	for (int i = count - 1; i >= 0; i--)
		cout << out[i];

	system("pause");
	return 0;

}

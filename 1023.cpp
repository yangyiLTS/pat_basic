#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {

	int in[10];
	for (int i = 0; i < 10; i++) 
		cin >> in[i];

	for (int i = 1; i < 10; i++) {
		if (in[i] > 0) {
			cout << i;
			in[i]--;
			break;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < in[i]; j++) 
			cout << i;
	}

	system("pause");
	return 0;

}

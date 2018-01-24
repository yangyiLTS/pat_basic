#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {

	char s[1000];
	int out[10] = { 0 };
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++) 
		out[s[i] - 48]++;

	for (int i = 0; i < 10; i++) {
		if (out[i] == 0) continue;
		cout << i << ':' << out[i] << endl;
	}

	system("pause");
	return 0;

}

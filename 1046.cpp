#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;


int main() {
	int n;
	cin >> n;
	int aWin = 0, bWin = 0;
	for (int i = 0; i < n; i++) {
		int ahan, ahua, bhan, bhua, ans;
		cin >> ahan >> ahua >> bhan >> bhua;
		ans = ahan + bhan;
		if (ans != ahua && ans == bhua) {
			bWin++;
		}
		else if (ans == ahua && ans != bhua) {
			aWin++;
		}
	}
	cout << bWin << ' ' << aWin << endl;
	system("pause");
	return 0;
}

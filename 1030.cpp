#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;


int main() {
	int number[100010] = { 0 };
	int  n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number, number + n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		long long x = (long long)number[i] * p;
		int result = 1;
		if (number[n - 1] <= x) {
			result = n;
		}
		else {
			int l = i + 1, r = n - 1, mid;
			while (l < r) {
				mid = (l + r) / 2;
				if (number[mid] <= x) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			result = l;
		}
		ans = max(ans, result - i);
	}
	cout << ans;

	system("pause");
	return 0;
}

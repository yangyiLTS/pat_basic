#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
bool isPrime(long long n);

int main()
{
	int M, N;
	cin >> M >> N;
	if (M == 0) {
		if (N == 0) return 0;
		else M = 1;
	}
	if (N == 0) return 0;
	long long i = 2;
	int count = 0;
	int enterFlag = 0;
	while (1) {
		if (isPrime(i)) {
			count++;
			if (count < M) {
				i++;
				continue;
			}
			if (enterFlag == 0) {
				cout << i;
				enterFlag++;
			}
			else {
				cout << ' ' << i;
				enterFlag++;
			}
			
		}
		if (enterFlag == 10) {
			cout << endl;
			enterFlag = 0;
		}
		i++;
		if (count == N) break;
	}

	system("pause");
	return 0;
}

bool isPrime(long long n) {
	long long i;
	for (i = 2; i*i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

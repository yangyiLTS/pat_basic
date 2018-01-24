#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool isPrime(int n);

int main()
{
	int temp = 3, count = 0;
	int max;
	cin >> max;
	if (max < 3)
	{
		cout << 0;
		return 0;
	}
	for (int i = 3; i <= max; i++) {
		if (isPrime(i)) {
			if (i - temp == 2)
				count++;
			temp = i;
		}
	}

	cout << count;
	system("pause");
	return 0;
}

bool isPrime(int n)
{
	int i;
	for (i = 2; i *i <= n; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	if (n == 0)
		return 0;
	int b, s, g;

	b = n / 100;
	s = n / 10 - b * 10;
	g = n % 10;

	for (int i = 0; i < b; i++)
		cout << 'B';
	for (int i = 0; i < s; i++)
		cout << 'S';
	for (int i = 1; i <= g; i++)
		cout << i;
	
	system("pause");
	return 0;
}
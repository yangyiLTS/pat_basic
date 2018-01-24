#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


int main()
{
	queue<int>	q;
	while (1) {
		int a, n;
		cin >> a >> n;
		q.push(a);
		q.push(n);
		if (getchar() == '\n')
			break;
	}
	if (q.empty()) 
		return 0;
	else {
		int a, b, a1, b1;
		a = q.front();
		q.pop();
		b = q.front();
		q.pop();
		a1 = a * b;
		b1 = b - 1;
		if (a1)
			cout << a1 << ' ' << b1;
		else if (b1 == -1 && a1 == 0)
			cout << "0 0";
	}
	while (1) {
		if (q.empty())
			break;
		int a, b, a1, b1;
		a = q.front();
		q.pop();
		b = q.front();
		q.pop();
		a1 = a * b;
		b1 = b - 1;
		if (a1)
			cout << ' ' << a1 << ' ' << b1;
		else if (!b1)
			cout << " 0 0";

	}
	system("pause");
	return 0;
}

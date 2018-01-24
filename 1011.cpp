#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		long long A, B, C;
		cin >> A >> B >> C;
		cout << "Case #" << i + 1 << ": ";
		if (A + B > C)cout << "true" << endl;
		else cout << "false" << endl;
	}
	
	system("pause");
	return 0;
}

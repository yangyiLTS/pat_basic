#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int main() {
	
	char A[1001];
	int B;
	cin >> A >> B;
	if (B > 9) return 0;
	char Q[1001];
	int temp = 0, yu;
	int i = 0;
	for (; i < 1001; i++) {
		if (A[i] == '\0') { 
			Q[i] = '\0';
			break;
		}
		int result;
		result = (A[i] - 48 + temp) / B;
		Q[i] = result;
		yu = (A[i] - 48 + temp) % B;
		temp = yu * 10;
	}

	int j = 0;
	while (Q[j] == '\0') j++;
	while (j < i) {
		cout << int(Q[j]);
		j++;
	}
	if (j == 2) cout << 0;

	cout << ' ' << yu;
	system("pause");
	return 0;
}

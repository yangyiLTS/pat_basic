#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



int main() {

	int n;
	cin >> n;
	int Aw[3] = { 0, 0, 0 }, Bw[3] = { 0, 0, 0 };

	for (int i = 0; i < n; i++) {
		char A, B;
		cin >> A >> B;
		if (A == 'C') {
			if (B == 'J') Aw[1]++;
			else if (B == 'B') Bw[0]++;
		}
		if (A == 'B') {
			if (B == 'C') Aw[0]++;
			else if (B == 'J') Bw[2]++;
		}
		if (A == 'J') {
			if (B == 'B') Aw[2]++;
			else if (B == 'C') Bw[1]++;
		}
	}
	int aw = Aw[0] + Aw[1] + Aw[2];
	int bw = Bw[0] + Bw[1] + Bw[2];
	cout << aw << ' ' << n - aw - bw << ' ' << bw << endl;
	cout << bw << ' ' << n - aw - bw << ' ' << aw << endl;

	if (Aw[2] > Aw[1]) {
		if (Aw[0] < Aw[2]) cout << 'J';
		else cout << 'B';
	}
	else if (Aw[1] > Aw[2]) {
		if (Aw[0] < Aw[1]) cout << 'C';
		else cout << 'B';
	}
	else if (Aw[0] >= Aw[1]) cout << 'B';
	else if (Aw[1] > Aw[0]) cout << 'C';
	else cout << 'B';

	cout << ' ';

	if (Bw[2] > Bw[1]) {
		if (Bw[0] < Bw[2]) cout << 'J';
		else cout << 'B';
	}
	else if (Bw[1] > Bw[2]) {
		if (Bw[0] < Bw[1]) cout << 'C';
		else cout << 'B';
	}
	else if (Bw[0] >= Bw[1]) cout << 'B';
	else if (Bw[0] < Bw[1]) cout << 'C';
	else cout << 'B';

	system("pause");
	return 0;
}

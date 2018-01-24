#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {
	int a;
	cin >> a;

	int r[4];

	r[0] = a % 10;
	r[1] = (a / 10) % 10;
	r[2] = (a / 100) % 10;
	r[3] = (a / 1000) % 10;

	sort(r, r + 4);
	if (r[0] == r[1] && r[1] == r[2] && r[2] == r[3]) {
		cout << setfill('0') << setw(4) << a << " - " << setfill('0') << setw(4) << a << " = " << "0000" << endl;
		return 0;

	}
	
		while (1) {
			int max, min;
			max = r[3] * 1000 + r[2] * 100 + r[1] * 10 + r[0];
			min = r[3] + r[2] * 10 + r[1] * 100 + r[0] * 1000;
			a = max - min;
			cout << setfill('0') << setw(4) << max << " - " << setfill('0') << setw(4) << min << " = " << setfill('0') << setw(4) << a << endl;
			if (a == 6174) {
				break;
			}
			r[0] = a % 10;
			r[1] = (a / 10) % 10;
			r[2] = (a / 100) % 10;
			r[3] = a / 1000;
			sort(r, r + 4);
		}

	


	system("pause");
	return 0;

}

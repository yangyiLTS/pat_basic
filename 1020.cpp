#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {
	double number, need;
	cin >> number >> need;
	double kucun[1010];
	double zongjia[1010];
	float danjia[1010];
	for (int i = 0; i < number; i++) cin >> kucun[i];
	for (int i = 0; i < number; i++) cin >> zongjia[i];
	for (int i = 0; i < number; i++) danjia[i] = float(zongjia[i]) / float(kucun[i]);

	//bublesort 

	int i, j;
	double tmp1;
	float tmp2;
	for (i = 0; i < number - 1; i++) {
		tmp1 = kucun[i];
		tmp2 = danjia[i];
		for (j = number - 1; j > i; j--) {
			if (danjia[j] > tmp2) {
				danjia[i] = danjia[j];
				danjia[j] = tmp2;
				tmp2 = danjia[i];

				kucun[i] = kucun[j];
				kucun[j] = tmp1;
				tmp1 = kucun[i];

			}
		}

	}

	float income = 0;
	double zongdun = 0;

	for (int i = 0; i < number; i++) {
		if (zongdun < need) {
			zongdun += kucun[i];
		}
		if (zongdun < need) {
			income += float(kucun[i])*danjia[i];
		}
		else {
			income += float((kucun[i] - (zongdun - need)))*danjia[i];
			cout << setprecision(2) << std::fixed << income;
			system("pause");
			return 0;
		}

	}
	cout << setprecision(2) << std::fixed << income;

	system("pause");
	return 0;

}

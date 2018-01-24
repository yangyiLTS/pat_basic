#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
/*
模拟插入排序和归并排序的每一步过程，其中归并排序使用非递归方式会比较方便
先进行插入排序，如果发现其中一步与给定序列吻合，计算出下一步并输出
如果不是插入排序，则是归并排序
*/
const int N = 111;
int n;
int origin[N], tempOri[N], changed[N];

bool isSame(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

void showArray(int a[]) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1) {
			cout << ' ';
		}
	}
	cout << endl;
	return;
}


bool inserSort() {
	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (i != 1 && isSame(tempOri, changed)) {
			flag = true;
		}
		int temp = tempOri[i], j = i;
		while (j > 0 && tempOri[j - 1] > temp) {
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if (flag == true) {
			return true;
		}
	}
	return false;
}

void mergeSort() {
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2) {
		if (step != 2 && isSame(tempOri, changed)) {
			flag = true;
		}
		for (int i = 0; i < n; i += step) {
			sort(tempOri + i, tempOri + min(i + step, n));
		}
		if (flag == true) {
			showArray(tempOri);
			return;
		}
	}
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> origin[i];
		tempOri[i] = origin[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> changed[i];
	}
	if (inserSort()) {
		cout << "Insertion Sort\n";
		showArray(tempOri);
	}
	else {
		cout << "Merge Sort\n";
		for (int i = 0; i < n; i++) {
			tempOri[i] = origin[i];
		}
		mergeSort();
	}
	system("pause");
	return 0;
}

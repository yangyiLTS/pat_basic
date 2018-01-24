#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
typedef long long ll;
struct student {
	ll id;
	int TestSeat;
	int ExamSeat;
} s[1000];
bool cmp(student a, student b) {
	return a.TestSeat < b.TestSeat;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i].id >> s[i].TestSeat >> s[i].ExamSeat;
	}
	sort(s, s + N, cmp);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int j;
		cin >> j;
		cout << s[j - 1].id << ' ' << s[j - 1].ExamSeat << endl;
	}
	system("pause");
	return 0;
}

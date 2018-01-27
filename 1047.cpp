#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
// #include <iomanip>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;


int main() {
	int N;
	cin >> N;
	int S[100010] = { 0 };
	int maxTeam = 0, maxScore = 0;
	for (int i = 0; i < N; i++) {
		int team, number, score;
		scanf("%d-%d %d", &team, &number, &score);
		if (i == 0) {
			maxTeam = team;
			maxScore = score;
			S[team] += score;
		}
		else {
			S[team] += score;
			if (S[team] > maxScore) {
				maxScore = S[team];
				maxTeam = team;
			}
		}
	}
	cout << maxTeam << ' ' << maxScore;


	system("pause");
	return 0;
}

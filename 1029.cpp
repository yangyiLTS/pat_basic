#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Node {
	char c;
	int order;
} str[96];

bool cmp(Node a, Node b) {
	return a.order < b.order;
}


int main() {
	for (int i = 0; i < 96; i++) {
		str[i].order = -1;
	}
	char s1[81], s2[81];
	cin >> s1 >> s2;
	int count = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] > 96 && s1[i] < 123) {
			if (str[s1[i] - 32].order >= 0) {
				continue;
			}
			str[s1[i] - 32].order = count++;
			str[s1[i] - 32].c = s1[i] - 32;
		}
		else {
			if (str[s1[i]].order >= 0) {
				continue;
			}
			str[s1[i]].order = count++;
			str[s1[i]].c = s1[i];
		}
	}
	for (int i = 0; s2[i] != '\0'; i++) {
		if (s2[i] > 96 && s2[i] < 123) {
			str[s2[i] - 32].order = -1;
		}
		else {
			str[s2[i]].order = -1;
		}
	}
	sort(str, str + 95, cmp);

	for (int i = 0; i < 96; i++) {
		if (str[i].order >= 0) {
			cout << str[i].c;
		}
	}
	system("pause");
	return 0;
}

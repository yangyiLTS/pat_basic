#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Node {
	char name[5];
	int date;
}node[100010];

bool cmp(Node a, Node b) {
	return a.date < b.date;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char s[11];
		cin >> node[i].name >> s;
		node[i].date = 0;
		for (int j = 0; j < 10; j++) {
			if (s[j] == '/')  continue;
			node[i].date = node[i].date * 10 + s[j] - 48;
		}
	}
	sort(node, node + n, cmp);
	int head = -1, end = -1;
	for (int i = 0; i < n; i++) {
		if (node[i].date > 18140905 && node[i].date <= 20140906) {
			head = i;
			break;
		}
	}
	for (int i = head; i < n; i++) {
		if (node[i].date > 18140905 && node[i].date <= 20140906) {
			end = i;
		}
	}
	if (head == -1) {
		cout << 0;
	}
	else {
		cout << end - head + 1 << ' ' << node[head].name << ' ' << node[end].name;
	}
	system("pause");
	return 0;
}

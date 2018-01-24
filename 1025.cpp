#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int NMAX = 100010;

struct Node {
	int address, data, next;
	int order;
};

Node node[NMAX];

bool cmp(Node a, Node b) {
	return a.order < b.order;
}

int main() {
	for (int i = 0; i < NMAX; i++) {
		node[i].order = NMAX;
	}

	int head, n, K, adress;
	cin >> head >> n >> K;
	for (int i = 0; i < n; i++) {
		cin >> adress;
		cin >> node[adress].data >> node[adress].next;
		node[adress].address = adress;
	}

	int count = 0;
	int p = head;
	while (p != -1) {
		node[p].order = count;
		count++;
		p = node[p].next;
	}

	sort(node, node + NMAX, cmp);
	n = count;
	for (int i = 0; i < n / K; i++) {
		for (int j = (i + 1)*K - 1; j > i*K; j--) {
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i*K].address, node[i*K].data);

		if (i < n / K - 1) {
			printf("%05d\n", node[(i + 2)*K - 1].address);
		}
		else {
			if (n % K == 0) {
				printf("-1\n");
			}
			else {
				printf("%05d\n", node[(i + 1)*K].address);
				for (int i = n / K*K; i < n; i++) {
					printf("%05d %d ", node[i].address, node[i].data);
					if (i < n-1) {
						printf("%05d\n", node[i + 1].address);
					}
					else {
						printf("-1\n");
					}
				}
			}

		}
	}
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

int main()
{
	int N, M;
	cin >> N >> M;
	Node *head = new Node;
	Node *prev = head;
	if (N == 1) {
		int a;
		cin >> a;
		cout << a;
		return 0;
	}
	cin >> head->data;
	for (int i = 1; i < N - 1; i++) {
		Node *n = new Node;
		prev->next = n;
		cin >> n->data;
		prev = n;
	}
	Node *end = new Node;
	prev->next = end;
	cin >> end->data;
	end->next = head;
	for (int i = 0; i < N-(M%N); i++)
		head = head->next;
	Node *p = head;
	for (int i = 0; i < N - 1; i++) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data;

	system("pause");
	return 0;
}

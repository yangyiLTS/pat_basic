#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

/*
段错误
非常的瓜皮
因为分配大量节点时内存超限
有空用数组改写
http://blog.csdn.net/apie_czx/article/details/45200921
http://blog.csdn.net/jk110333/article/details/19685127
*/

struct Node{
	int data;
	Node *next;
	Node *prior;
};

Node *head;
Node *eptr;

void DelElem(Node *N);

int main()
{
	int count;
	cin >> count;
	if (count == 0) {
		cout << "N N N N N";
		return 0;
	}

	for (int i = 0; i < count; i++) {
		Node *N = new Node;
		if (i == 0) {
			N->prior = NULL;
			head = N;
			eptr = N;

			cin >> N->data;
		}

		else if (i < count - 1) {
			N->prior = eptr;
			eptr->next = N;
			cin >> N->data;
			eptr = N;
		}

		else if (i == count - 1) {
			N->prior = eptr;
			eptr->next = N;
			cin >> N->data;
			N->next = NULL;
			eptr = N;
		}
	}

	/*----------A1----------*/
	Node *tag = head;
	int A1 = 0, A1flag = 0;
	while (1) {
		if (tag->data % 5 == 0 && tag->data % 2 == 0) {
			A1 += tag->data;
			A1flag = 1;
			DelElem(tag);
		}
		if (!tag->next)
			break;
		tag = tag->next;
	}
	if (!A1flag) cout << "N ";
	else cout << A1 << ' ';

	/*----------A2----------*/
	tag = head;
	int A2 = 0, A2flag = 0;
	while (1) {
		if (tag->data % 5 == 1) {
			A2flag++;
			if (A2flag % 2) A2 += tag->data;
			else A2 -= tag->data;
			DelElem(tag);
		}
		if (!tag->next)
			break;
		tag = tag->next;
	}
	if (!A2flag) cout << "N ";
	else cout << A2 << ' ';

	/*----------A3----------*/
	tag = head;
	int A3 = 0, A3flag;
	while (1) {
		if (tag->data % 5 == 2) {
			A3++;
			A3flag = 1;
			DelElem(tag);
		}
		if (!tag->next)
			break;
		tag = tag->next;
	}
	if (!A3flag) cout << "N ";
	else cout << A3 << ' ';

	/*----------A4----------*/
	tag = head;
	float A4 = 0;
	int A4flag = 0;
	while (1) {
		if (tag->data % 5 == 3) {
			A4flag++;
			A4 += tag->data;
			DelElem(tag);
		}
		if (!tag->next)
			break;
		tag = tag->next;
	}
	if (!A4flag) cout << "N ";
	else cout << setprecision(1) << setiosflags(ios::fixed) << A4  / A4flag << ' ';

	/*----------A5----------*/
	tag = head;
	int A5 = 0;
	while (1) {
		if (tag->data % 5 == 4) {
			if (tag == head)
				A5 = tag->data;
			else {
				if (tag->data > A5)
					A5 = tag->data;
			}
		}
		if (!tag->next)
			break;
		tag = tag->next;
	}
	if (!A5) cout << 'N';
	else cout << A5;


	system("pause");
	return 0;
}

void DelElem(Node *N) {
	if (N->prior == NULL) {
		head = N->next;
		N->next->prior = N->prior;
		return;
	}
	if (N->next == NULL) {
		eptr = N->prior;
		N->prior->next = N->next;
		return;
	}
	N->prior->next = N->next;
	N->next->prior = N->prior;
}

// 13 1 2 3 4 5 6 7 8 9 10 20 16 18
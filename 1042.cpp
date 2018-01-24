#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;


int main() {
	char str1[1010] ;
	int count[30] = { 0 };
	cin.getline(str1,1010);
	int len = strlen(str1);
	for (int i = 0; i < len; i++) {
		if (str1[i] >= 'a'&&str1[i] <= 'z') {
			count[str1[i] - 'a']++;
		}
		else if (str1[i] >= 'A'&&str1[i] <= 'Z') {
			count[str1[i] - 'A']++;
		}
	}
	int target = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] > count[target]) {
			target = i;
		}
	}

	printf("%c %d\n", target + 'a', count[target]);
	system("pause");
	return 0;
}

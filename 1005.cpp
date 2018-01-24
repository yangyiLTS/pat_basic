#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void sortNum(int *p, int length);

int main()
{
	int numCount;
	cin >> numCount;
	if (numCount == 0) return 0;
	int rawArr[100];
	for (int i = 0; i < numCount; i++)
		cin >> rawArr[i];
	
	for (int i = 0; i < numCount; i++)
	{
		int a = rawArr[i];
		while (a > 1)
		{
			if (a % 2 == 0)
				a /= 2;
			else
				a = (3 * a + 1) / 2;
			for (int j = 0; j < numCount; j++)
			{
				if (rawArr[j] == 0) continue;
				if (rawArr[j] == a && i != j)
				{
					rawArr[j] = 0;
				}
			}
		}
	}
	sortNum(rawArr, numCount);
	
	if (rawArr[0] != 0)
		cout << rawArr[0];
	else
		return 0;
	
	for (int i = 1; i < numCount; i++)
	{
		if (rawArr[i] == 0) 
			break;
		else
			cout << ' ' << rawArr[i];
	}
	system("pause");
	return 0;
}

void sortNum(int *p, int length)
{
	int i, j, tmp;
	for (i = 0; i < length - 1; i++)
	{
		tmp = p[i];
		for (j = length - 1; j > i; j--) 
		{
			if (p[j] > tmp)
			{
				p[i] = p[j];
				p[j] = tmp;
				tmp = p[i];
			}
		}
	}
}
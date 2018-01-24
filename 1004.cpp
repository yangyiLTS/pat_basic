#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void printName(char *p);

int main() 
{
	int stuNum;
	cin >> stuNum;
	getchar();
	if(stuNum == 0)
		return 0;
	int minScore = 100, maxScore = 0;
	char minStr[26], maxStr[26];
	for (int i = 0; i < stuNum; i++)
	{

		char rawStr[26];
		cin.getline(rawStr, 26);
		char *ptr1 = rawStr;
		if (i == 0)
		{
			strcpy(minStr, rawStr);
			strcpy(maxStr, rawStr);
		}
		int sum = 0;
		int spaceFlag = 0;
		for (int j = 0; j < 26; j++)
		{
			
			
			if (spaceFlag == 2)
			{
				if (*(ptr1 + 2) == '\0')
				{
					sum = (int(*ptr1) - 48) * 10 + int(*(ptr1 + 1) - 48);
					break;
				}
				else if (*(ptr1 + 1) == '\0')
				{
					sum = int(*ptr1) - 48;
					break;
				}
				else if (*(ptr1 + 3) == '\0')
				{
					sum = 100;
					break;
				}
			}
			if(*ptr1 == ' ')
				spaceFlag++;
			ptr1++;
		}
		if (sum > maxScore || sum == 100)
		{
			maxScore = sum;
			strcpy(maxStr, rawStr);
		}
		if (sum < minScore || sum == 0)
		{
			minScore = sum;
			strcpy(minStr, rawStr);
		}
	}
	
	printName(maxStr);
	cout << endl;
	printName(minStr);
	system("pause");
	return 0;
}

void printName(char *p)
{
	int i = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
			i++;
		if (i == 2)
			break;
		cout << *p;
		p++;
	}
	
}
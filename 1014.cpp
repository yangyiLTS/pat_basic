#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
不知道什么回事
唉
*/
int main()
{
	char A1[65], A2[65];
	char B1[65], B2[65];
	cin >> A1 >> A2 >> B1 >> B2;

	int DAY = 0, H = 0, M = -1;

	int dflag = 0;
	for (int i = 0; i < 65; i++) {
		for (int j = dflag; j < 65; j++) {
			if (!DAY && A1[i] >= 'A' && A1[i] <= 'G' && A2[j] == A1[i]) {
				DAY = A1[i] - 64;
				dflag = i + 1;
				break;
			}
			if (DAY && (A1[i] >= 'A' && A1[i] <= 'N' || A1[i] >='0' && A1[i] <= '9') && A2[j] == A1[i]) {
				if (A1[i] >= '0' && A1[i] <= '9')
					H = A1[i] - 48;
				else
					H = A1[i] - 55;
				break;
			}
		}
		if (DAY && H) break;
	}



	for (int i = 0; i < 65; i++) {
		if ((B1[i] == B2[i] && B1[i] >= 'a' && B1[i] <= 'z') || (B1[i] >= 'A' && B1[i] <= 'Z')) {
			M = i;
			break;
		}
	}
	if (DAY > 7 || H > 24 || M > 59) return 0;

	switch (DAY)
	{
	case 1:cout << "MON "; break;
	case 2:cout << "TUE "; break;
	case 3:cout << "WED "; break;
	case 4:cout << "THU "; break;
	case 5:cout << "FRI "; break;
	case 6:cout << "SAT "; break;
	case 7:cout << "SUN "; break;
	default:
		break;
	}
	if (H < 10) cout << 0;
	cout << H << ':';
	if (M < 10) cout << 0 << M;
	else cout << M;
	system("pause");
	return 0;
}

/*

#include<stdio.h>
#include<string.h> 
#define MAX 100
int main()
{
	char H[][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char st1[MAX],st2[MAX],st3[MAX],st4[MAX];
	scanf("%s",&st1);scanf("%s",&st2);scanf("%s",&st3);scanf("%s",&st4);
	int i,t=0;
	for(i=0;i<strlen(st1);i++)
	{
		if(t==0&&st1[i]==st2[i]&&st1[i]>='A'&&st1[i]<='G')//第1对相同的!大写英文字母!
		{
			t=1;
			printf("%s ",H[st1[i]-'A']);
			continue;
		}
		else if(t==1&&st1[i]==st2[i]&&(st1[i]>='A'&&st1[i]<='N'||st1[i]>='0'&&st1[i]<='9'))//第2对相同的!字符!
		{
			if(st1[i]>='0'&&st1[i]<='9')
			{printf("0%d:",st1[i]-'0');break;} 
			else if(st1[i]>='A'&&st1[i]<='N')
			{printf("%d:",st1[i]-'A'+10);break;}
		}
	}
	int j;
	for(j=0;j<strlen(st3);j++)
	{
	if(st3[j]==st4[j]&&(st3[j]>='a'&&st3[j]<='z'||st3[j]>='A'&&st3[j]<='Z'))//后面两字符串第1对相同的!英文字母(未说大小那么都考虑进去)!
		{
			if(j<10)
			printf("0%d",j);
			else
			printf("%d",j);
		}
	}
	return 0;
}

*/
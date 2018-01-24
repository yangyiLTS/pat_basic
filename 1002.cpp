#include <iostream>

using namespace std;

int main()
{
	int strNumber;
	cin >> strNumber;
	bool result[strNumber];
	for(int i = 0; i < strNumber; i++)
		result[i] = 0;
	for(int i = 0; i < strNumber; i++)
	{
		char strArr[100];
		cin >> strArr;
		bool P_flag = 0, T_flag = 0, c_flag = 1;
		int A1 = 0, A2 = 0, A3 = 0;
		char *charPtr = strArr;
		while(*charPtr != '\0')
		{
			char y = *charPtr;
			if(y != 'P' && y != 'A' && y != 'T')
			{
				result[i] == false;
				c_flag = 0;
				break;
			}

			if(y == 'P')
			{
				if(P_flag)
				{
					result[i] = false;
					c_flag = 0;
					break;
				}
				if(!P_flag)
					P_flag = 1;
			}

			if(y == 'T')
			{
				if(T_flag)
				{
					result[i] = false;
					c_flag = 0;
					break;
				}
				else
					T_flag = 1;
			}

			if(y == 'A')
			{
				if(!P_flag && !T_flag)
					A1++;
				else if(P_flag && !T_flag)
					A2++;
				else if(P_flag && T_flag)
					A3++;
			}
			//cout << A1 << endl << A2 << endl << A3 << endl;
			charPtr++;
		}
		if(!P_flag || !T_flag)
		{
			result[i] = false;
			continue;
		}
		if(c_flag)
		{
			if(A2 == 1)
			{
				if(A1 == A3)
					result[i] = 1;
				else
					result[i] = 0;
			}
			else if(A2 > 1)
			{
				if(A3 == (A2 * A1))
					result[i] = 1;
				else
					result[i] = 0;
			}
			else
				result[i] = 0;
		}
	}
	for(int i = 0; i < strNumber; i++)
	{
		if(result[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}

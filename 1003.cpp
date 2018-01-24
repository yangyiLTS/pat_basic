#include <iostream>

using namespace std;


int main()
{
    int stutNum;
    cin >> stuNum;
    for(int i = 0; i < stuNum; i++) 
    {
        char rawStr[26];
        cin >> rawStr;
        char *ptr1 = rawPtr;
        int minScore, maxScore;
        for(int j = 0; j < 26; j++)
        {
            int spaceFlag = 0;
            int sBit = 0, sum = 0, xishu = 1;
            if(spaceFlag == 2)
            {
                if (*(ptr1 + 2) == '\0')
                {
                    sum = (int(*ptr) - 48) *10 + int(*(ptr + 1) -48;
                    break;
                }
                else if (*(ptr1 + 1) == '\0')
                {
                    sum =int(*ptr) -48;
                    break;
                }
                else if (*(ptr1 + 3) == '\0')
                {

                }
            }
            if(*ptr1 == " ")
                spaceFlag++;
            ptr1++;
        }
    }

    system('pause');
    return 0;
}
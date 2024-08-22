#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int nMax = 0;
    int nCharCount[33] = { 0 };
    string strString;
    cin >> strString;

    for (int i = 0; i < strString.size(); i++)
    {
        if (strString[i] >= 97 && strString[i] <= 122)
            strString[i] -= 32;

        nCharCount[strString[i] - 65]++;
    }

    for (int i = 0; i < 33; i++)
        nMax = max(nMax, nCharCount[i]);

    bool bDuplicate = false;
    for (int i = 0; i < 33; i++)
    {
        if (nCharCount[i] == nMax)
        {
            if (bDuplicate)
            {
                cout << "?";
                return 0;
            }
            else
                bDuplicate = true;
        }
    }
    for (int i = 0; i < 33; i++)
    {
        if (nCharCount[i] == nMax)
        {
            cout << (char)(i + 65);
            return 0;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

long g_ResultValue[100001][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nCount = 0;
    cin >> nCount;

    g_ResultValue[1][1] = 1;
    g_ResultValue[1][2] = 0;
    g_ResultValue[1][3] = 0;

    g_ResultValue[2][1] = 0;
    g_ResultValue[2][2] = 1;
    g_ResultValue[2][3] = 0;

    g_ResultValue[3][1] = 1;
    g_ResultValue[3][2] = 1;
    g_ResultValue[3][3] = 1;


    int nMax = 4;
    for (int i = 0; i < nCount; i++)
    {
        int nValue = 0;
        cin >> nValue;

        for (int j = nMax; j <= nValue; j++)
        {
            g_ResultValue[j][1] = (g_ResultValue[j - 1][2] + g_ResultValue[j - 1][3]) % 1000000009;
            g_ResultValue[j][2] = (g_ResultValue[j - 2][1] + g_ResultValue[j - 2][3]) % 1000000009;
            g_ResultValue[j][3] = (g_ResultValue[j - 3][1] + g_ResultValue[j - 3][2]) % 1000000009;
        }

        cout << (g_ResultValue[nValue][1] + g_ResultValue[nValue][2] + g_ResultValue[nValue][3]) % 1000000009 << '\n';
        
        nMax = max(nMax, nValue);
    }
}
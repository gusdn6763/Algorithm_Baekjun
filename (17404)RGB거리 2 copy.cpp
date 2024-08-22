#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nHouseCount = 0;
    cin >> nHouseCount;

    int nHouseValue[1001][3] = { 0 };
    int nDp[1001][3] = { 0 };

    for (int i = 1; i < nHouseCount + 1; i++)
        for (int j = 0; j < 3; j++)
            cin >> nHouseValue[i][j];

    int nMin = 1000001;
    for (int i = 0; i < 3; i++)
    {

        for (int k = 0; k < 3; k++)
        {
            nDp[1][k] = nHouseValue[1][k];
            if (i != k)
                nDp[1][k] = 1000001;
        }

        for (int j = 2; j < nHouseCount + 1; j++)
        {
            nDp[j][0] = min(nDp[j - 1][1], nDp[j - 1][2]) + nHouseValue[j][0];
            nDp[j][1] = min(nDp[j - 1][0], nDp[j - 1][2]) + nHouseValue[j][1];
            nDp[j][2] = min(nDp[j - 1][0], nDp[j - 1][1]) + nHouseValue[j][2];
            
            if (j == nHouseCount)
                nDp[j][i] = 1000001;
        }
        nMin = min(min(min(nDp[nHouseCount][0], nDp[nHouseCount][1]), nDp[nHouseCount][2]), nMin);
    }
    cout << nMin;
    //0 빨 
    //1 초
    //2 파
}
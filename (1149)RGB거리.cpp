#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long dp[1000001] = { 0 };

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

    int nMin = INT_MAX;
    for (int i = 1; i < nHouseCount + 1; i++)
    {
        nDp[i][0] = min(nDp[i - 1][1], nDp[i - 1][2]) + nHouseValue[i][0];
        nDp[i][1] = min(nDp[i - 1][0], nDp[i - 1][2]) + nHouseValue[i][1];
        nDp[i][2] = min(nDp[i - 1][0], nDp[i - 1][1]) + nHouseValue[i][2];

    }
    nMin = min(min(nDp[nHouseCount][0], nDp[nHouseCount][1]), nDp[nHouseCount][2]);
    cout << nMin;
    //0 빨
    //1 초
    //2 파
}
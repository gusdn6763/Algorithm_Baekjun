#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dp[501][501] = { 0 };
int arr[501][501] = { 0 };

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nCount = 0;
    cin >> nCount;

    for (int i = 1; i < nCount + 1; i++)
        for (int j = 1; j < i + 1; j++)
            cin >> arr[i][j];

    dp[1][1] = arr[1][1];
    for (int i = 2; i < nCount + 1; i++)
        for (int j = 1; j < i + 1; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];

    int nMax = 0;
    for (int i = 1; i < nCount + 1; i++)
        nMax = max(dp[nCount][i], nMax);

    cout << nMax << '\n';
}
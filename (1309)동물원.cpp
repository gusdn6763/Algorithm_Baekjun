#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long dp[100001][3] = { 0 };

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nCorralCount = 0;
    cin >> nCorralCount;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i < nCorralCount + 1; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % 9901;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % 9901;
    }
    cout << (dp[nCorralCount][0] + dp[nCorralCount][1] + dp[nCorralCount][2]) % 9901;
}
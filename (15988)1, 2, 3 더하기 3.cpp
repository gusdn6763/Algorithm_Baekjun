#include <iostream>
#include <vector>

using namespace std;

long long dp[1000001] = { 0 };

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count, num;
    cin >> count;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    int nMax = 3;
    for (int i = 0; i < count; i++)
    {
        cin >> num;
        for (int j = nMax; j < num; j++)
            dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;

        cout << dp[num - 1] << "\n";
        nMax = max(nMax, num);
    }
}
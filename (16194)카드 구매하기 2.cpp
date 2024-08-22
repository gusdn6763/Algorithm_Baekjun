#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int maxCard, cardValue[1001] = { 0 };
    int dp[10001] = { 0 };

    for (int i = 1; i <= 10000; i++)
        dp[i] = 10001;

    cin >> maxCard;
    for (int i = 1; i <= maxCard; i++)
        cin >> cardValue[i];

    dp[1] = cardValue[1];
    for (int i = 2; i <= maxCard; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = min(dp[i], cardValue[j] + dp[i - j]);

    cout << dp[maxCard] << "\n";
}
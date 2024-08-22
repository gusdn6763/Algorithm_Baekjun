#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dp[100001] = { 0 };
int dp2[100001] = { 0 };
int arr[100001] = { 0 };
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, nResult = INT_MIN;

    cin >> num;

    for (int i = 1; i < num + 1; i++)
    {
        cin >> arr[i];
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    for (int i = num; i >= 0; i--)
        dp2[i] = max(dp2[i + 1] + arr[i], arr[i]);

    //한개를 삭제한다는 조건 보다, 한개이상 선택해야 한다는 조건이 우선입니다.
    for (int i = 1; i < num + 1; i++)
        nResult = max(dp[i], nResult);

    for (int i = 1; i < num; i++) 
        nResult = max(dp[i - 1] + dp2[i + 1], nResult);

    cout << nResult << '\n';
    
}
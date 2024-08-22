#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nCount = 0, nMax = 1;
    int dp[1001] = { 0 };
    int arr[1001] = { 0 };
    int result[1001] = { 0 };
    stack<int> st;

    cin >> nCount;
    for (int i = 1; i < nCount + 1; i++)
        cin >> arr[i];
    for (int i = 1; i < nCount + 1; i++)
    {
        dp[i] = 1;

        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                result[i] = dp[j];
                nMax = max(nMax, dp[i]);
            }
        }
    }

    for (int i = nCount; nMax != 0; i--)
    {
        if (result[i] == nMax - 1)
        {
            st.push(arr[i]);
            nMax--;
        }
    }
    cout << st.size() << '\n';
    while (st.empty() == false)
    {
        cout << st.top() << ' ';
        st.pop();
    }


    return 0;
}
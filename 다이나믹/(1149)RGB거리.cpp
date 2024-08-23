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

    //0 빨
    //1 초
    //2 파
    int nHouseValue[1001][3] = { 0 };
    int nDp[1001][3] = { 0 };

    for (int i = 1; i < nHouseCount + 1; i++)
        for (int j = 0; j < 3; j++)
            cin >> nHouseValue[i][j];

    int nMin = INT_MAX;
    for (int i = 1; i < nHouseCount + 1; i++)
    {
        //i 번째 집을 빨간색을 색칠한 경우 = 이전 집(초파)중에 최소비용값 + i 번째집 빨간색 값
        nDp[i][0] = min(nDp[i - 1][1], nDp[i - 1][2]) + nHouseValue[i][0];

        //i 번째 집을 초록색을 색칠한 경우 = 이전 집(빨파)중에 최소비용값 + i 번째집 초록색 값
        nDp[i][1] = min(nDp[i - 1][0], nDp[i - 1][2]) + nHouseValue[i][1];

        //i 번째 집을 파란색을 색칠한 경우 = 이전 집(빨초)중에 최소비용값 + i 번째집 파란색 값
        nDp[i][2] = min(nDp[i - 1][0], nDp[i - 1][1]) + nHouseValue[i][2];
    }
    nMin = min(min(nDp[nHouseCount][0], nDp[nHouseCount][1]), nDp[nHouseCount][2]);
    cout << nMin;
}
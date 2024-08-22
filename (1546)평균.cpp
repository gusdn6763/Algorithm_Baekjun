#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nCount = 0, nMax = 0;
    double fList[1001] = { 0 };
    double fTotal = 0.f;
    cin >> nCount;

    for (int i = 0; i < nCount; i++)
    {
        int nTmp = 0;
        cin >> nTmp;

        nMax = max(nMax, nTmp);
        fList[i] = nTmp;
    }
    for (int i = 0; i < nCount; i++)
        fTotal += fList[i] / nMax * 100;

    cout << fTotal / nCount;

    return 0;
}
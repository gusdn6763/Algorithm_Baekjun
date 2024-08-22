#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nCount = 3;


   // cin >> nCount;
    vector<int> vResult(nCount);

    for (int i = 0; i < nCount; i++)
        cin >> vResult[i];

    for (int i = 0; i < nCount - 1; i++)
    {
        for (int j = i + 1; j < 3;j++)//nCount - 1; j++)
        {
            if (vResult[i] > vResult[j])
            {
                int nTmp = vResult[i];
                vResult[i] = vResult[j];
                vResult[j] = nTmp;
            }
        }
    }

    for (int i = 0; i < vResult.size(); i++)
        cout << vResult[i] << ' ';

    return 0;
}
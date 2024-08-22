#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int GetSize(int num)
{
    int nCount = 0;

    do
    {
        nCount++;
        num /= 10;
    } while (num != 0);

    return nCount;
}

bool bCheckPossible(int num, bool bImPossibleList[10])
{
    do 
    {
        int nT = num % 10;
        if (bImPossibleList[nT] == true)
            return false;
        num /= 10;
    } while (num != 0);
    return true;
}

int main()
{
    int nPos = 100, nGoalPos = 0;
    int nClickCount = 500001;
    int nImpossibleCount = 0;
    bool bImPossibleList[10] = { false };

    cin >> nGoalPos >> nImpossibleCount;
    for (int i = 0; i < nImpossibleCount; i++)
    {
        int nTmp = 0;
        cin >> nTmp;
        bImPossibleList[nTmp] = true;
    }

    if (nPos > nGoalPos)
        nClickCount = nPos - nGoalPos;
    else
        nClickCount = nGoalPos - nPos;

    for (int i = 0; i < 1000000; i++)
    {
        if (bCheckPossible(i, bImPossibleList))
        {
            if (i > nGoalPos)
                nClickCount = min(nClickCount, GetSize(i) + i - nGoalPos);
            else
                nClickCount = min(nClickCount, GetSize(i) + nGoalPos - i);
        }
    }
    
    cout << nClickCount << '\n';

    return 0;
}
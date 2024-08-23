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
        if (bImPossibleList[nT] == false)
            return false;
        num /= 10;
    } while (num != 0);

    return true;
}

int main()
{
    int nCurrentChannel = 100, nGoalChannel = 0;
    int nClickCount = 500001;
    int nImpossibleCount = 0;
    bool bPossibleList[10];
    std::fill_n(bPossibleList, 10, true);

    cin >> nGoalChannel >> nImpossibleCount;
    for (int i = 0; i < nImpossibleCount; i++)
    {
        int nTmp = 0;
        cin >> nTmp;
        bPossibleList[nTmp] = false;
    }

    if (nCurrentChannel > nGoalChannel)
        nClickCount = nCurrentChannel - nGoalChannel;
    else
        nClickCount = nGoalChannel - nCurrentChannel;

    //0번 채널부터 시작
    for (int i = 0; i < 1000000; i++)
    {
        //i번째 채널이 전부 클릭 가능시
        if (bCheckPossible(i, bPossibleList))
        {
            //현재 가장 근접하게 이동할 수 있는 채널을 구한 후 +-로 채널이동
            if (i > nGoalChannel)
                nClickCount = min(nClickCount, GetSize(i) + i - nGoalChannel);
            else
                nClickCount = min(nClickCount, GetSize(i) + nGoalChannel - i);
        }
    }

    cout << nClickCount << '\n';

    return 0;
}
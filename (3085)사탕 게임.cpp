#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nCount = 0, nMax = 0;
    char cBoard[50][50] = {' '};

    cin >> nCount;

    for (int i = 0; i < nCount; i++)
        for (int j = 0; j < nCount; j++)
            cin >> cBoard[i][j];

    for (int i = 0; i < nCount; i++)
    {
        for (int j = 1; j < nCount + 1; j++)
        {
            char cChangeOne = cBoard[i][j - 1];
            char cChangeTwo = cBoard[i + 1][j - 1];
            cBoard[i][j - 1] = cChangeTwo;
            cBoard[i + 1][j - 1] = cChangeOne;

            for (int k = 0; k < nCount; k++)
            {
                int nTmp = 1;
                for (int l = 0; l < nCount - 1; l++)
                {
                    if (cBoard[l][k] == cBoard[l + 1][k])
                        nTmp++;
                    else if (nTmp > 1)
                        break;
                }
                nMax = max(nMax, nTmp);

                nTmp = 1;
                for (int l = 0; l < nCount - 1; l++)
                {
                    if (cBoard[k][l] == cBoard[k][l + 1])
                        nTmp++;
                    else if (nTmp > 1)
                        break;
                }
                nMax = max(nMax, nTmp);
            }
            
            cBoard[i][j - 1] = cChangeOne;
            cBoard[i + 1][j - 1] = cChangeTwo;
        }

        for (int j = 1; j < nCount; j++)
        {
            char cChangeOne = cBoard[i][j - 1];
            char cChangeTwo = cBoard[i][j];
            cBoard[i][j - 1] = cChangeTwo;
            cBoard[i][j] = cChangeOne;

            for (int k = 0; k < nCount; k++)
            {
                int nTmp = 1;
                for (int l = 0; l < nCount - 1; l++)
                {
                    if (cBoard[l][k] == cBoard[l + 1][k])
                        nTmp++;
                    else if (nTmp > 1)
                        break;
                }
                nMax = max(nMax, nTmp);

                nTmp = 1;
                for (int l = 0; l < nCount - 1; l++)
                {
                    if (cBoard[k][l] == cBoard[k][l + 1])
                        nTmp++;
                    else if (nTmp > 1)
                        break;
                }

                nMax = max(nMax, nTmp);
            }

            cBoard[i][j - 1] = cChangeOne;
            cBoard[i][j] = cChangeTwo;
        }
    }

    cout << nMax;

    return 0;
}
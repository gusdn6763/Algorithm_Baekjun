#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nOne = 0, nTwo = 0, nThree = 0;
    int nTmpOne = 1, nTmpTwo = 1, nTmpThree = 1;

    cin >> nOne >> nTwo >> nThree;

    int nMax = 1;

    while ((nTmpOne == nOne && nTmpTwo == nTwo && nTmpThree == nThree) == false)
    {
        nTmpOne++;
        nTmpTwo++;
        nTmpThree++;

        if (nTmpOne > 15)
            nTmpOne = 1;

        if (nTmpTwo > 28)
            nTmpTwo = 1;

        if (nTmpThree > 19)
            nTmpThree = 1;

        nMax++;
    }

    cout << nMax;

    return 0;
}
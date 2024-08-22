#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nHour = 0;
    int nMinuate = 0;
    int nAddTime = 0;

    cin >> nHour >> nMinuate >> nAddTime;

    nMinuate += nAddTime;
    while (nMinuate >= 60)
    {
        if (nMinuate >= 60)
        {
            nHour++;
            nMinuate -= 60;
        }
        if (nHour >= 24)
        {
            nHour = 0;
        }
    }

    cout << nHour << ' ' << nMinuate;
}
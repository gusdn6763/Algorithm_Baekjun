#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() 
{
	int nCount = 0;
	long long nTotalCount = 0;
	cin >> nCount;

	int nTmp = 1;
	int nNumber = 1;
	for (int i = 1; nNumber <= nCount; i++)
	{
		nTmp *= 10;

		if (nTmp > nCount)
			nTmp = nCount + 1;

		nTotalCount += (nTmp - nNumber) * i;
		nNumber *= 10;
	}

	cout << nTotalCount;
}
//1 ~ 9 -> 1
//10 ~ 99 -> 2
//100 ~ 999 -> 3

//9 -> 9
//99 -> 189
//100 -> 192
//120 -> 252

//9 -> (9 * 1)
//90 -> (9 * 1) + (90 - 10) * 2 
//120 -> (9 * 1) + (90 * 2) + (21 * 3)

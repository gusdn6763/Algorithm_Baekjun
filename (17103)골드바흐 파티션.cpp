#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool check[1000001];

void CheckPrime()
{
	for (int i = 0; i < 1000001; i++)
		check[i] = true;
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		if (check[i] == false)
			continue;
		for (int t = i * 2; t <= 1000000; t += i)
			check[t] = false;
	}
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	CheckPrime();

	int nCount, nValue, nTotalCount = 0;
	cin >> nCount;

	for (int i = 0; i < nCount; i++)
	{
		nTotalCount = 0;
		cin >> nValue;

		for (int i = 2; i <= nValue - i; i++)
		{
			if (check[i] == true && check[nValue - i] == true)
				nTotalCount++;
		}

		cout << nTotalCount << '\n';
	}
	return 0;
}
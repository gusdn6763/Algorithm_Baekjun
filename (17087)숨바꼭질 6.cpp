#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long one(long long  num1, long long  num2)
{
	long long  tmp;
	while (num1 != 0)
	{
		tmp = num2 % num1;
		num2 = num1;
		num1 = tmp;
	}
	return num2;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int nChild = 0;
	long long nPos;
	long long lResult = LLONG_MAX;

	cin >> nChild;
	cin >> nPos;

	vector<int> vMinus(nChild);
	for (int i = 0; i < nChild; i++)
	{
		cin >> vMinus[i];
		vMinus[i] = abs(vMinus[i] - nPos);
	}

	lResult = vMinus[0];

	for (int j = 1; j < nChild; j++)
		lResult = one(lResult, vMinus[j]);

	cout << lResult << "\n";
}
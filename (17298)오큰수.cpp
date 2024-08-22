#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int nCount = 0;
	cin >> nCount;
	stack<int> nValue;
	vector<int> vTmp(nCount);
	vector<int> v(nCount);
	for (int i = 0; i < nCount; i++)
	{
		int nTmp = 0;
		cin >> nTmp;

		vTmp[i] = nTmp;
		v[i] = -1;
		if (nValue.size() > 0)
		{
			while(nValue.size() && nTmp > vTmp[nValue.top()])
			{
				v[nValue.top()] = nTmp;
				nValue.pop();
			}
		}

		nValue.push(i);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}
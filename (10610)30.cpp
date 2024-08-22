#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int tmp_num[100000];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string num;
	int i, sum = 0;
	cin >> num;

	for (i = 0; i < num.size(); i++)
	{
		tmp_num[i] = num[i] - 48;
	}
	sort(tmp_num, tmp_num + i);
	while (i)
	{
		sum += tmp_num[i - 1];
		if (i == 1)
			break;
		i--;
	}
	if (tmp_num[0] == 0 && sum % 3 == 0)
	{
		sort(num.begin(), num.end(), greater<>());
		cout << num << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
}
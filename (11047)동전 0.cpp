#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int coin_value[1000001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count, result, i, tmp = 0, coin_count = 0;
	

	cin >> count >> result;
	for (i = 0; i < count; i++)
	{
		cin >> coin_value[i];
	}
	while (result != tmp)
	{
		while (1)
		{
			if (result < coin_value[i - 1] || result < tmp + coin_value[i - 1])
			{
				i--;
			}
			else
			{
				tmp += coin_value[i - 1];
				coin_count++;
				break ;
			}
		}
	}
	cout << coin_count;
}
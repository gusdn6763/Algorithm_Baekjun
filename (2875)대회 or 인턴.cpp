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

	int female, male, ship, count = 0;

	cin >> female >> male >> ship;
	while (1)
	{
		if (female > 1 && male > 0)
		{
			female -= 2;
			male -= 1;
			count++;
		}
		else
		{
			break;
		}
	}
	while (ship > 0)
	{
		if (female > 0)
		{
			female--;
			ship--;
		}
		else if (male > 0)
		{
			male--;
			ship--;
		}
		else
		{
			count--;
			female += 2;
			male += 1;
		}
	}

	cout << count;
}
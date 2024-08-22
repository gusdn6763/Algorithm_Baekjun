#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int tmp_num[100000];

//1 1
//3 2
//5 3
//7 4
//11 5
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, move = 1;

	cin >> N >> M;
	if (N == 2)
	{
		move = min(4, (M + 1) / 2);
	}
	else if (N > 2 &&  M < 7)
	{
		move = min(M, 4);
	}
	else if (N > 2 && M > 6)
	{
		move = M - 2;
	}
	cout << move << "\n";
}
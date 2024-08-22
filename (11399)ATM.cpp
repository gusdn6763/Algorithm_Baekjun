#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int test[10001];
int tmp[10001];

void merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (test[i] >= test[j])
		{
			tmp[k++] = test[j++];
		}
		else
		{
			tmp[k++] = test[i++];
		}
	}
	if (i > mid)		//왼쪽값이 더 클때 tmp[k++] = test[i++];의 뒤에 나오는값 출력
	{
		for (int l = j; l <= right; l++)
		{
			tmp[k++] = test[l];
		}
	}
	else				//오른쪽값이 더 클때 tmp[k++] = test[j++];의 뒤에 나오는값 출력
	{
		for (int l = i; l <= mid; l++)
		{
			tmp[k++] = test[l];
		}
	}
	for (int l = left; l <= right; l++)
	{
		test[l] = tmp[l];
	}
}

void merge_sort(int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;
	long long result = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> test[i];
	}
	merge_sort(0, count - 1);

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			result += tmp[j];
		}
	}
	if (count == 1)
	{
		cout << test[0] << "\n";
	}
	else
	{
		cout << result << "\n";
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int tmp[10001];
int num[10001];
int one = 0;

void merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if ((tmp[i] >= tmp[j]))
		{
			num[k++] = tmp[j++];
		}
		else
		{
			num[k++] = tmp[i++];
		}
	}
	if (i > mid)		//왼쪽값이 더 클때 tmp[k++] = test[i++];의 뒤에 나오는값 출력
	{
		for (int l = j; l <= right; l++)
		{
			num[k++] = tmp[l];
		}
	}
	else				//오른쪽값이 더 클때 tmp[k++] = test[j++];의 뒤에 나오는값 출력
	{
		for (int l = i; l <= mid; l++)
		{
			num[k++] = tmp[l];
		}
	}
	for (int l = left; l <= right; l++)
	{
		tmp[l] = num[l];
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

int get_count(int min, int max, int count)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (num[i] >= min && num[i] <= max)
		{
			result++;
		}
	}
	return (result);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count, positive, negative, zero, one;
	int result = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> tmp[i];
	}
	merge_sort(0, count - 1);
	positive = get_count(1,10000,count);
	negative = get_count(-10000, -1, count);
	zero = get_count(0, 0, count);
	one = get_count(1, 1, count);
	if (positive % 2 == 1)
	{
		tmp[count++] = 1;
	}
	if (negative % 2 == 1)
	{
		if (!zero)
		{
			tmp[count++] = 1;
		}
	}
	merge_sort(0, count - 1);

	for (int i = 0; i < count; i += 2)
	{
		if(!(num[i] == 1 && num[i + 1] == 1))
			result += num[i] * num[i + 1];
	}
	if (count == 1)
	{
		cout << tmp[0] << "\n";
	}
	else
	{
		cout << result + one << "\n";
	}
}
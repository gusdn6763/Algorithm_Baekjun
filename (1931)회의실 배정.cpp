#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

pair <int, int > meeting_time[100001];

bool compare(pair<int, int>a, pair<int, int>b) 
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count, end_time;
	int result = 1;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> meeting_time[i].first >> meeting_time[i].second;
	}
	sort(meeting_time, meeting_time + count, compare);
	end_time = meeting_time[0].second;
	for (int i = 1; i < count; i++)
	{

		if (meeting_time[i].first >= end_time)
		{
			end_time = meeting_time[i].second;
			result++;
		}
	}
	cout << result << "\n";
}
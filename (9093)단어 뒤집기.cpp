#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int nCount = 0;
	string str;
	stack<char> stack;

	cin >> nCount;

	cin.ignore();
	for (int i = 0; i < nCount; i++)
	{
		stack.empty();
		getline(cin, str);
		str += '\n';
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ' || str[j] == '\n')
			{
				while (stack.size() != 0)
				{
					cout << stack.top();
					stack.pop();
				}

				cout << ' ';
			}
			else
				stack.push(str[j]);
		}
		cout << '\n';
	}

	return 0;
}
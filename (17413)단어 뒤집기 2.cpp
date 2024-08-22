#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	stack<char> stack;

	getline(cin, str);
	str += '\n';
	for (int j = 0; j < str.size() + 1; j++)
	{
		if (str[j] == ' ' || str[j] == '\n' || str[j] == '<')
		{
			while (stack.size() != 0)
			{
				cout << stack.top();
				stack.pop();
			}

			if (str[j] != '<')
				cout << ' ';
		}
		else
			stack.push(str[j]);

		if (str[j] == '<')
		{
			while (str[j] != '>')
				cout << str[j++];

			cout << '>';
		}
	}
	cout << '\n';
	

	return 0;
}
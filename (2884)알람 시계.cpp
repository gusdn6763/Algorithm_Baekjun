#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() 
{
	int nHousr, nMinuate;
	cin >> nHousr >> nMinuate;

	nMinuate -= 45;
	if (nMinuate < 0)
	{
		nMinuate += 60;
		nHousr -= 1;

		if (nHousr < 0)
			nHousr = 23;
	}

	cout << nHousr << ' ' << nMinuate;
	return 0;
}
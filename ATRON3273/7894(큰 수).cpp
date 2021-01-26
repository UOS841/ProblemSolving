#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		int m;
		cin >> m;

		double sum_log_10 = 0;
		for (int i = 1; i <= m; i++)
		{
			sum_log_10 = sum_log_10 + log10(i);
		}

		cout << (int)sum_log_10 + 1 << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n)
{
	vector<int> dp(2);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp.push_back(dp[i - 1] + dp[i - 2]);
		if (dp[i] >= 1000000)
		{
			dp[i] %= 1000000;
		}
	}
	return dp[n];
}

int main()
{
	long long int n;
	cin >> n;
	
	if (n >= 1500000)
	{
		n %= 1500000;
	}

	cout << fibonacci((int)n);
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a < c)
		{
			return c;
		}
		else
		{
			return a;
		}
	}
	else
	{
		if (b < c)
		{
			return c;
		}
		else
		{
			return b;
		}
	}
}

int calc_max_drinkable_wine(int wine_num, vector<int> wine)
{
	if (wine_num == 1)
	{
		return wine[1];
	}
	else if (wine_num == 2)
	{
		return wine[1] + wine[2];
	}

	vector<int> dp(wine_num + 1);
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= wine_num; i++)
	{
		dp[i] = max(
			dp[i - 1],							// 이번 와인은 안 마시는 경우
			dp[i - 2] + wine[i],				// 전 와인 건너뛰고 이번 와인 마시는 경우
			dp[i - 3] + wine[i - 1] + wine[i]);	// 두 번 연속해서 마시는 경우
	}

	return dp[wine_num];
}

int main()
{
	int n;
	cin >> n;
	vector<int> wine(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}

	cout << calc_max_drinkable_wine(n, wine) << endl;
	return 0;
}
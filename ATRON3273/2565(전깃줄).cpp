#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<pair<int, int>> line(num);
	vector<int> dp(num, 1);

	for (int i = 0; i < num; i++)
	{
		cin >> line[i].first >> line[i].second;
	}

	sort(line.begin(), line.end());

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (line[i].second > line[j].second)
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	cout << num - *max_element(dp.begin(), dp.end());
}
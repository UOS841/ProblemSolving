#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int output[101];

int main()
{
	int num, a, b;
	int result = 0;
	cin >> num;

	vector<pair<int, int>> v;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				if (output[j] >= output[i])
				{
					output[i] = output[j] + 1;
				}
			}
		}
		result = max(result, output[i]);
	}

	cout << num - result << '\n';
	return 0;
}
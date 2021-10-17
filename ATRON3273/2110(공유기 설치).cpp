#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_max_distance(vector<int>& house, int num_AP)
{
	sort(house.begin(), house.end());
	int house_count = house.size();
	int max_len = 0;
	int min = 1, max = house[house_count - 1] - house[0];

	while (min <= max)
	{
		int mid = (min + max) / 2;
		int before_installed = 0;
		int AP_count = 1;

		for (int i = 1; i < house_count; i++)
		{
			if (house[i] >= house[before_installed] + mid)
			{
				AP_count++;
				before_installed = i;
			}
		}

		if (AP_count < num_AP)
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}
	}
	
	return max;
};

int main()
{
	int N, C;
	cin >> N >> C;
	vector<int> house(N);
	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}

	cout << get_max_distance(house, C);

	return 0;
}
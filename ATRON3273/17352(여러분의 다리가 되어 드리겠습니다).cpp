#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_group(vector<int>& group, int island)
{
	if (group[island] == island)
	{
		return island;
	}
	else
	{
		return group[island] = find_group(group, group[island]);
	}
}

pair<int, int> make_bridge(vector<pair<int, int>> bridge_info)
{
	int num_island = bridge_info.size() + 2;
	vector<int> group(num_island);
	for (int i = 0; i < group.size(); i++)
	{
		group[i] = i;
	}

	// 다리 정보 탐색
	for (int i = 0; i < bridge_info.size(); i++)
	{
		int island1 = bridge_info[i].first - 1;
		int island2 = bridge_info[i].second - 1;
		int group_island1 = find_group(group, island1);
		int group_island2 = find_group(group, island2);

		// group 번호가 작은 쪽으로 group 통일
		if (group_island1 > group_island2)
		{
			group[group_island1] = group_island2;
		}
		else
		{
			group[group_island2] = group_island1;
		}
	}

	for (int i = 0; i < num_island; i++)
	{
		find_group(group, i);
	}

	sort(group.begin(), group.end());
	group.erase(unique(group.begin(), group.end()), group.end());

	return make_pair(group[0] + 1, group[1] + 1);
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> bridge(N - 2);
	for (int i = 0; i < N - 2; i++)
	{
		int island1, island2;
		cin >> island1 >> island2;
		bridge[i] = make_pair(island1, island2);
	}

	pair<int, int> new_bridge = make_bridge(bridge);

	cout << new_bridge.first << " " << new_bridge.second << endl;
	return 0;
}
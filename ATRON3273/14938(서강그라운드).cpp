#define INF 10000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_vector(vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

vector<int> get_distance(int start_node, vector<vector<pair<int, int>>> road)
{
	queue<pair<int, int>> q;
	int node_count = road.size() - 1;

	vector<int> distance(node_count + 1, INF);
	vector<bool> visited(node_count + 1, false);

	q.push(make_pair(start_node, 0));
	distance[start_node] = 0;

	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_path_len = q.front().second;
		q.pop();

		if (distance[cur_node] > cur_path_len)
		{
			distance[cur_node] = cur_path_len;
		}

		for (int i = 0; i < road[cur_node].size(); i++)
		{
			int next_node = road[cur_node][i].first;
			int road_len = road[cur_node][i].second;

			if (distance[next_node] > cur_path_len + road_len)
			{
				q.push(make_pair(next_node, cur_path_len + road_len));
			}
		}
	}

	//print_vector(distance);

	return distance;
}

int get_accessible_item_count(vector<int> distance, vector<int> item_info, int search_range)
{
	int count = 0;

	for (int i = 1; i < distance.size(); i++)
	{
		if (distance[i] <= search_range)
		{
			//cout << i << " ";
			count += item_info[i];
		}
	}
	//cout << "/ " << count << endl;
	return count;
}

int get_max_item_count(vector<vector<pair<int, int>>> road, vector<int> item_info, int search_range)
{
	int node_count = road.size() - 1;
	int max_item_count = 0;

	for (int i = 1; i <= node_count; i++)
	{
		//cout << i << " : ";
		// 해당 노드에서부터 다른 노드로의 거리를 구함
		vector<int> distance = get_distance(i, road);
		// 해당 노드에서 수색범위 내 구할 수 있는 아이템의 갯수를 구함
		int item_count = get_accessible_item_count(distance, item_info, search_range);

		if (max_item_count < item_count)
		{
			max_item_count = item_count;
		}
	}

	return max_item_count;
}

int main()
{
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> item(n + 1);
	vector<vector<pair<int, int>>> road(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}
	for (int i = 0; i < r; i++)
	{
		int edge1, edge2, tmp_distance;
		cin >> edge1 >> edge2 >> tmp_distance;
		road[edge1].push_back(make_pair(edge2, tmp_distance));
		road[edge2].push_back(make_pair(edge1, tmp_distance));
	}

	cout << get_max_item_count(road, item, m);

	return 0;
}
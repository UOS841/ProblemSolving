#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<vector<pair<float, int>>> calc_each_star_distance(vector<pair<float, float>> star)
{
	int star_count = star.size();
	vector<vector<pair<float, int>>> star_conn_info(star_count);
	for (int i = 0; i < star_count; i++)
	{
		for (int j = i + 1; j < star_count; j++)
		{
			float s1_x = star[i].first, s1_y = star[i].second;
			float s2_x = star[j].first, s2_y = star[j].second;
			float distance = sqrt((s1_x - s2_x) * (s1_x - s2_x) + (s1_y - s2_y) * (s1_y - s2_y));
			
			star_conn_info[i].push_back(make_pair(distance, j));
			star_conn_info[j].push_back(make_pair(distance, i));
		}
	}

	return star_conn_info;
}

float get_cost(vector<vector<pair<float, int>>> info)
{
	float total_cost = 0;
	int star_count = info.size();
	vector<bool> visited(star_count, false);

	priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
	pq.push(make_pair(0, 1));
	int cur_conn_star_count = 0;

	while (!pq.empty() || cur_conn_star_count < star_count)
	{
		float cur_cost = pq.top().first;
		int cur_star = pq.top().second;
		pq.pop();

		if (visited[cur_star] == false)
		{
			total_cost += cur_cost;
			visited[cur_star] = true;
			cur_conn_star_count++;

			for (int i = 0; i < info[cur_star].size(); i++)
			{
				float next_cost = info[cur_star][i].first;
				int next_star = info[cur_star][i].second;

				if (visited[next_star] == false)
				{
					pq.push(make_pair(next_cost, next_star));
				}
			}
		}
	}

	return total_cost;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<float, float>> star(n);
	for (int i = 0; i < n; i++)
	{
		cin >> star[i].first >> star[i].second;
	}
	cout << fixed;
	cout.precision(2);
	cout << get_cost(calc_each_star_distance(star));

	return 0;
}
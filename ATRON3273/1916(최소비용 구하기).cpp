#define INF 0x7FFFFFFF

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct bus
{
	int terminate_city;
	int cost;
} Bus;

int main()
{
	int N, M, begin_city, end_city;
	cin >> N;
	cin >> M;

	vector<vector<Bus>> bus_list(N + 1);
	vector<int> move_cost(N + 1, INF);

	for (int i = 0; i < M; i++)
	{
		int city1, city2, cost;
		cin >> city1 >> city2 >> cost;
		bus_list[city1].push_back({ city2, cost });
	}
	cin >> begin_city >> end_city;

	move_cost[begin_city] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push(make_pair(move_cost[begin_city], begin_city));
	while (!q.empty())
	{
		int cur = q.top().second;
		q.pop();

		for (int i = 0; i < bus_list[cur].size(); i++)
		{
			Bus next = bus_list[cur][i];
			if (move_cost[next.terminate_city] > move_cost[cur] + next.cost)
			{
				move_cost[next.terminate_city] = move_cost[cur] + next.cost;
				q.push(make_pair(move_cost[next.terminate_city], next.terminate_city));
			}
		}
	}
	cout << move_cost[end_city];

	return 0;
}
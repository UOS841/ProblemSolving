#include <iostream>
#include <vector>
#include <queue>

#define MAX 20001
#define INF 100000000

using namespace std;

int main()
{
	int V, E, start;
	cin >> V >> E;
	cin >> start;

	vector<pair<int, int>> graph[MAX];
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back(make_pair(to, cost));
	}

	vector<int> distance(V + 1, INF);
	distance[start] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push(make_pair(0, start));

	while (!Q.empty())
	{
		int cur = Q.top().second;
		int cur_cost = Q.top().first;
		Q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (distance[next] > cur_cost + next_cost)
			{
				distance[next] = cur_cost + next_cost;
				Q.push(make_pair(distance[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << distance[i] << "\n";
		}
	}

	return 0;
}
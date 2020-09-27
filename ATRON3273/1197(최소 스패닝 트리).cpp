#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int V, E, total_weight = 0;
	cin >> V >> E;

	vector<vector<pair<int, int>>> graph(V + 1);
	vector<bool> visited(V + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		graph[A].push_back(make_pair(C, B));
		graph[B].push_back(make_pair(C, A));
	}

	visited[1] = true;
	for (int i = 0; i < graph[1].size(); i++)
	{
		if (visited[graph[1][i].second] == false)
		{
			queue.push(make_pair(graph[1][i].first, graph[1][i].second));
		}
	}
	while (!queue.empty())
	{
		int cur_node = queue.top().second;
		int cur_node_weight = queue.top().first;
		queue.pop();

		if (visited[cur_node] == false)
		{
			visited[cur_node] = true;
			total_weight += cur_node_weight;
		}

		for (int j = 0; j < graph[cur_node].size(); j++)
		{
			int next_node = graph[cur_node][j].second;
			int next_node_weight = graph[cur_node][j].first;

			if (visited[next_node] == true)
			{
				continue;
			}
			else
			{
				queue.push(make_pair(next_node_weight, next_node));
			}
		}
	}
	cout << total_weight;

	return 0;
}
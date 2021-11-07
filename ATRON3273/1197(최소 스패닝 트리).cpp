#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int get_weight(vector<vector<pair<int, int>>> graph)
{
	int answer = 0;
	int graph_size = graph.size() - 1;
	vector<bool> visited(graph_size + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	int cur_conn_node_count = 0;

	while (!pq.empty() || cur_conn_node_count < graph_size)
	{
		int cur_weight = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (visited[cur_node] == false)
		{
			answer += cur_weight;
			visited[cur_node] = true;
			cur_conn_node_count++;

			for (int i = 0; i < graph[cur_node].size(); i++)
			{
				int next_weight = graph[cur_node][i].first;
				int next_node = graph[cur_node][i].second;

				if (visited[next_node] == false)
				{
					pq.push(make_pair(next_weight, next_node));
				}
			}
		}
	}

	return answer;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<vector<pair<int, int>>> graph(V + 1);
	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		graph[A].push_back(make_pair(C, B));
		graph[B].push_back(make_pair(C, A));
	}

	cout << get_weight(graph);

	return 0;
}
#define INF 0x0FFFFFFF

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>> graph, int start, int end)
{
	vector<int> distance(graph.size(), INF);
	distance[start] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(distance[start], start));

	while (!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].second;
			int next_distance = graph[cur][i].first;

			if (distance[next] > distance[cur] + next_distance)
			{
				distance[next] = distance[cur] + next_distance;
				pq.push(make_pair(distance[next], next));
			}
		}
	}

	if (distance[end] == INF)
	{
		return -INF;
	}
	else
	{
		return distance[end];
	}
}

int main()
{
	int N, E, v1, v2;
	int case1, case2;
	cin >> N >> E;
	vector<vector<pair<int, int>>> graph(N + 1);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	cin >> v1 >> v2;

	case1 = dijkstra(graph, 1, v1) + dijkstra(graph, v1, v2) + dijkstra(graph, v2, N);
	case2 = dijkstra(graph, 1, v2) + dijkstra(graph, v2, v1) + dijkstra(graph, v1, N);

	if (case1 > 0 || case2 > 0)
	{
		cout << ((case1 < case2) ? case1 : case2);
	}
	else
	{
		cout << -1;
	}

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
bool graph[1001][1001];
bool BFSvisited[1001];
bool DFSvisited[1001];

void BFS(int start)
{

	queue<int> Q;
	Q.push(start);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		if (BFSvisited[cur] == false)
		{
			BFSvisited[cur] = true;
			cout << cur << " ";

			for (int i = 1; i <= N; i++)
			{
				if (graph[cur][i] == true)
				{
					Q.push(i);
				}
			}
		}
	}
}

void DFS(int cur_node)
{
	DFSvisited[cur_node] = true;
	cout << cur_node << " ";
	for (int i = 1; i <= N; i++)
	{
		if (graph[cur_node][i] == true && DFSvisited[i] == false)
		{
			DFS(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		graph[node1][node2] = true;
		graph[node2][node1] = true;
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}
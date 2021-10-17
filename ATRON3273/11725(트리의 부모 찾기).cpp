#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> make_parent_info(vector<pair<int, int>>& list)
{
	int list_size = list.size();

	vector<vector<int>> child(list.size() + 2);
	child[0].push_back(1);
	for (int i = 0; i < list_size; i++)
	{
		int node1 = list[i].first;
		int node2 = list[i].second;
		
		child[node1].push_back(node2);
		child[node2].push_back(node1);
	}

	queue<int> q;
	vector<int> parent(list.size() + 2, -1);
	//vector<bool> visited(list.size() + 2, false);
	parent[1] = 0;
	//visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < child[cur].size(); i++)
		{
			/*
			if (visited[next] == false)
			{
				visited[cur] = true;
				q.push(next);

			}
			*/
			parent[next]
		}
	}

	return parent;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> node_list(N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> node_list[i].first >> node_list[i].second;
	}

	vector<int> parent_info = make_parent_info(node_list);

	for (int i = 2; i <= N; i++)
	{
		cout << parent_info[i] << '\n';
	}

	return 0;
}
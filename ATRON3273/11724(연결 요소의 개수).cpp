#include <iostream>
#include <vector>

using namespace std;

int parent[1001];

int find(int n)
{
	if (n == parent[n])
	{
		return n;
	}
	else
	{
		return parent[n] = find(parent[n]);
	}
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a <= b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

int main()
{
	int N, M, count = 0;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			merge(i, graph[i][j]);
		}
	}

	vector<bool> group(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		if (group[parent[i]] == false)
		{
			group[parent[i]] = true;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (group[i] == true)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}
#define MAX 100001

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[MAX];
bool visited[MAX];

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	dist[N] = 0;
	visited[N] = true;


	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (visited[cur * 2] == false && cur * 2 <= MAX - 1)
		{
			dist[cur * 2] = dist[cur];
			visited[cur * 2] = true;
			q.push(cur * 2);
		}
		if (visited[cur - 1] == false && cur - 1 >= 0)
		{
			dist[cur - 1] = dist[cur] + 1;
			visited[cur - 1] = true;
			q.push(cur - 1);
		}
		if (visited[cur + 1] == false && cur + 1 <= MAX - 1)
		{
			dist[cur + 1] = dist[cur] + 1;
			visited[cur + 1] = true;
			q.push(cur + 1);
		}

	}

	cout << dist[K];
	return 0;
}
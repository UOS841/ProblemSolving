#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<int>> distance(N, vector<int>(M, -1));

	queue<pair<pair<int, int>, int>> Q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				distance[i][j] = 0;
				Q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	while (!Q.empty())
	{
		int cur_r = Q.front().first.first;
		int cur_c = Q.front().first.second;
		int cur_dist = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; i++)
		{
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];
			int next_dist = cur_dist + 1;

			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M)
			{
				if (distance[next_r][next_c] == -1 || distance[next_r][next_c] > next_dist)
				{
					distance[next_r][next_c] = next_dist;
					Q.push(make_pair(make_pair(next_r, next_c), next_dist));
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (answer < distance[i][j])
			{
				answer = distance[i][j];
			}
		}
	}
	cout << answer;

	return 0;
}
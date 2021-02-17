#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// up, down, left, right
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int main()
{
	int M, N;
	cin >> M >> N;

	vector<vector<int>> map(M, vector<int>(N));
	vector<vector<int>> dp(M, vector<int>(N, 0));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	
	priority_queue<pair<int, pair<int, int>>> Q;
	Q.push(make_pair(map[0][0], make_pair(0, 0)));
	dp[0][0] = 1;

	while (!Q.empty())
	{
		int cur_num = Q.top().first;
		int cur_r = Q.top().second.first;
		int cur_c = Q.top().second.second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_r = cur_r + dr[dir];
			int next_c = cur_c + dc[dir];
			if (next_r >= 0 && next_r < M && next_c >= 0 && next_c < N)
			{
				if (map[cur_r][cur_c] > map[next_r][next_c])
				{
					if (dp[next_r][next_c] == 0)
					{
						Q.push(make_pair(map[next_r][next_c], make_pair(next_r, next_c)));
					}
					dp[next_r][next_c] += dp[cur_r][cur_c];
				}
			}
		}
	}

	cout << dp[M - 1][N - 1];

	return 0;
}
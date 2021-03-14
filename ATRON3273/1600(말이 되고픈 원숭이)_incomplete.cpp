#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// up, down, left, right
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
// 시계 1, 2, 4, 5, 7, 8, 10, 11시 방향
int dr_h[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dc_h[8] = { 1, 2, 2, 1, -1, -2 ,-2, -1 };

int main()
{
	int K, W, H, answer;
	cin >> K;
	cin >> W >> H;

	vector<vector<int>> map(H, vector<int>(W));
	vector<vector<vector<int>>> distance(K + 1, vector<vector<int>>(H, vector<int>(W, -1)));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}

	// (r좌표, c좌표), (이동 횟수, 남은 능력 수)
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(0, 0), make_pair(0, K)));
	distance[K][0][0] = 0;

	while (!Q.empty())
	{
		int cur_r = Q.front().first.first;
		int cur_c = Q.front().first.second;
		int cur_num = Q.front().second.first;
		int cur_ability = Q.front().second.second;
		Q.pop();

		// 일단 상하좌우로 움직여 봄
		for (int i = 0; i < 4; i++)
		{
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];

			// 해당 좌표가 map 안에 있고
			if (next_r >= 0 && next_r < H && next_c >= 0 && next_c < W)
			{
				// 그 좌표가 평지이며
				if (map[next_r][next_c] == 0)
				{
					// 아직 방문하지 않았다면 기록, 큐에 넣음
					if (distance[cur_ability][next_r][next_c] == -1)
					{
						distance[cur_ability][next_r][next_c] = cur_num + 1;
						Q.push(make_pair(make_pair(next_r, next_c), make_pair(cur_num + 1, cur_ability)));
					}
				}
			}
		}

		// 현재 능력이 있다면 말이 이동할 수 있는 좌표로 움직여 봄
		if (cur_ability > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int next_r = cur_r + dr_h[i];
				int next_c = cur_c + dc_h[i];

				// 해당 좌표가 map 안에 있고
				if (next_r >= 0 && next_r < H && next_c >= 0 && next_c < W)
				{
					// 그 좌표가 평지이며
					if (map[next_r][next_c] == 0)
					{
						// 아직 방문하지 않았다면 기록, 큐에 넣음
						if (distance[cur_ability - 1][next_r][next_c] == -1)
						{
							distance[cur_ability - 1][next_r][next_c] = cur_num + 1;
							Q.push(make_pair(make_pair(next_r, next_c), make_pair(cur_num + 1, cur_ability - 1)));
						}
					}
				}
			}
		}
	}
	/*
	for (int k = 0; k <= K; k++)
	{
		cout << "k : " << k << endl;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << distance[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/

	answer = 400;
	for (int k = K; k >= 0; k--)
	{
		if (answer > distance[k][H - 1][W - 1])
		{
			answer = distance[k][H - 1][W - 1];
		}
	}
	cout << answer;

	return 0;
}
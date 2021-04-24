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
	vector<vector<int>> box(N, vector<int>(M));
	vector<vector<int>> day(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
		}
	}

	queue<pair<pair<int, int>, int>> q;
	bool is_ripe_all = true;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1)
			{
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	while (!q.empty())
	{
		int cur_r = q.front().first.first;
		int cur_c = q.front().first.second;
		int cur_day = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_r = cur_r + dr[dir];
			int next_c = cur_c + dc[dir];
			int next_day = cur_day + 1;

			// 다음 탐색 인덱스가 박스 안쪽이고
			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M)
			{
				// 초기에 안 익었고, 아직 안 익은 토마토라면
				if (day[next_r][next_c] == 0 && box[next_r][next_c] == 0)
				{
					// 큐에 push
					day[next_r][next_c] = next_day;
					q.push(make_pair(make_pair(next_r, next_c), next_day));
				}
			}
		}
	}

	// 제일 익는데 오래 걸린 토마토 탐색
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < day[i][j])
			{
				max = day[i][j];
			}
			// 초기에 안 익은 토마토인데 day의 값이 0인 경우
			if (day[i][j] == 0 && box[i][j] == 0)
			{
				// 결국 안 익은 토마토, 모든 토마토가 익지 않음
				is_ripe_all = false;
			}
		}
	}

	if (is_ripe_all == false)
	{
		printf("%d\n", -1);
	}
	else
	{
		// 처음에 모든 토마토가 익었으면 max엔 0이 들어감
		printf("%d\n", max);
	}

	return 0;
}
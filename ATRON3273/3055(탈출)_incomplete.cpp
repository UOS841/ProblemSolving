#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[50][50];

// up, down, left, right
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

vector<vector<int>> water_flow(int R, int C)
{
	vector<vector<bool>> visited(R, vector<bool>(C, false));	// 여기에 방문한 좌표인지 기록
	vector<vector<int>> flow_phase_map(R, vector<int>(C, 0));	// 여기에 각 좌표가 몇 단계에 물이 차는지 기록
	queue<pair<pair<int, int>, int>> Q;

	// map에서 물이 찬 지역('*')을 탐색한 후 queue에 push
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '*' && visited[i][j] == false)
			{
				Q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	while (!Q.empty())
	{
		int cur_R = Q.front().first.first;
		int cur_C = Q.front().first.second;
		int cur_phase = Q.front().second;
		Q.pop();
		
		// queue에서 pop한 좌표를 방문하지 않았다면 flow_phase_map에 기록
		if (visited[cur_R][cur_C] == false)
		{
			flow_phase_map[cur_R][cur_C] = cur_phase;
			visited[cur_R][cur_C] = true;

			// 해당 좌표에서 상하좌우로 이동하면서 다음 좌표 탐색
			for (int i = 0; i < 4; i++)
			{
				int next_flow_R = cur_R + dr[i];
				int next_flow_C = cur_C + dc[i];
				int next_phase = cur_phase + 1;

				// next 좌표가 map 안에 있고
				if (next_flow_R >= 0 && next_flow_R < R && next_flow_C >= 0 && next_flow_C < C)
				{
					// next 좌표의 map이 고슴도치가 다닐 수 있는 공간('.', 'S')임과 동시에 방문하지 않은 좌표라면
					if ((map[next_flow_R][next_flow_C] == '.' || map[next_flow_R][next_flow_C] == 'S') && visited[next_flow_R][next_flow_C] == false)
					{
						// 해당 좌표와 phase값을 queue에 push
						Q.push(make_pair(make_pair(next_flow_R, next_flow_C), next_phase));
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << flow_phase_map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	return flow_phase_map;
}

int go_home(vector<vector<int>> flow_phase, pair<int, int> hedgehog_loc, pair<int, int> home_loc, int R, int C)
{
	vector<vector<bool>> visited(R, vector<bool>(C, false));	// 여기에 방문한 좌표인지 기록
	vector<vector<int>> move_phase_map(R, vector<int>(C, 0));	// 여기에 각 좌표에 몇 단계만에 도달할 수 있는지 기록
	queue<pair<pair<int, int>, int>> Q;
	
	// queue에 초기 고슴도치 좌표를 push
	Q.push(make_pair(hedgehog_loc, 0));

	while (!Q.empty())
	{
		int cur_R = Q.front().first.first;
		int cur_C = Q.front().first.second;
		int cur_phase = Q.front().second;
		Q.pop();

		// queue에서 pop한 좌표를 방문하지 않았다면 move_phase_map에 기록
		if (visited[cur_R][cur_C] == false)
		{
			move_phase_map[cur_R][cur_C] = cur_phase;
			visited[cur_R][cur_C] = true;

			// 해당 좌표에서 상하좌우로 이동하면서 다음 좌표 탐색
			for (int i = 0; i < 4; i++)
			{
				int next_move_R = cur_R + dr[i];
				int next_move_C = cur_C + dc[i];
				int next_phase = cur_phase + 1;

				// next 좌표가 map 안에 있으면 계속 진행
				if (next_move_R >= 0 && next_move_R < R && next_move_C >= 0 && next_move_C < C)
				{
					// next 좌표의 map이 고슴도치가 다닐 수 있는 공간('.', 'S')임과 동시에 방문하지 않은 좌표고
					if ((map[next_move_R][next_move_C] == '.' || map[next_move_R][next_move_C] == 'S') && visited[next_move_R][next_move_C] == false)
					{
						// next 좌표에서의 phase가 물이 차는 단계보다 작아서 고슴도치가 그 좌표로 갈 수 있으면
						if (flow_phase[next_move_R][next_move_C] > next_phase)
						{
							// 해당 좌표와 phase값을 queue에 push
							Q.push(make_pair(make_pair(next_move_R, next_move_C), next_phase));
						}
					}
					// 만약 next 좌표가 비버 굴이면
					else if (map[next_move_R][next_move_C] == 'D')
					{
						// 해당 좌표와 phase값을 queue에 push
						Q.push(make_pair(make_pair(next_move_R, next_move_C), next_phase));
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << move_phase_map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	// 비버 굴 좌표까지 도달하는 phase를 return
	return move_phase_map[home_loc.first][home_loc.second];
}

int main()
{
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}

	// 고슴도치와 비버 굴 위치 파악
	pair<int, int> hedgehog_loc, home_loc;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')
			{
				hedgehog_loc.first = i;
				hedgehog_loc.second = j;
			}
			else if (map[i][j] == 'D')
			{
				home_loc.first = i;
				home_loc.second = j;
			}
		}
	}

	// 연산 후 답 출력
	int answer = go_home(water_flow(R, C), hedgehog_loc, home_loc, R, C);
	if (answer > 0)
	{
		cout << answer;
	}
	else
	{
		cout << "KAKTUS";
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct pipe
{
	pair<int, int> tail;
	pair<int, int> head;
} Pipe;

// dir : 0 -> 오른쪽 | 1 -> 대각 | 2 -> 아래 
Pipe move_pipe(Pipe pipe, int room_size, int dir)
{
	Pipe moved_pipe = pipe;
	if (dir == 0)		// - 방향
	{
		if (moved_pipe.head.second < room_size)
		{
			moved_pipe.tail = moved_pipe.head;
			moved_pipe.head.second++;
		}
		return moved_pipe;
	}
	else if (dir == 1)	// \ 방향
	{
		if (moved_pipe.head.first < room_size && moved_pipe.head.second < room_size)
		{
			moved_pipe.tail = moved_pipe.head;
			moved_pipe.head.first++;
			moved_pipe.head.second++;
		}
		return moved_pipe;
	}
	else if (dir == 2)	// | 방향
	{
		if (moved_pipe.head.first < room_size)
		{
			moved_pipe.tail = moved_pipe.head;
			moved_pipe.head.first++;
		}
		return moved_pipe;
	}
	else
	{
		return pipe;
	}
}

int pipe_dir(Pipe pipe)
{
	// 현재 파이프가 - 방향일 때
	if (pipe.tail.first == pipe.head.first && pipe.tail.second + 1 == pipe.head.second)
	{
		return 0;
	}
	// 현재 파이프가 \ 방향일 때
	else if (pipe.tail.first + 1 == pipe.head.first && pipe.tail.second + 1 == pipe.head.second)
	{
		return 1;
	}
	// 현재 파이프가 | 방향일 때
	else if (pipe.tail.first + 1 == pipe.head.first && pipe.tail.second == pipe.head.second)
	{
		return 2;
	}
	else
	{
		return -1;
	}
}

bool is_same_pipe(Pipe p1, Pipe p2)
{
	if (p1.head.first == p2.head.first && p1.head.second == p2.head.second && p1.tail.first == p2.tail.first && p1.tail.second == p2.tail.second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Pipe pipe;
	int N, cur_pipe_dir;

	cin >> N;

	vector<vector<int>> room(N + 1, vector<int>(N + 1));
	vector<vector<int>> count(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> room[i][j];
		}
	}

	pipe.tail = make_pair(1, 1);
	pipe.head = make_pair(1, 2);

	queue<Pipe> Q;
	Q.push(pipe);

	while (!Q.empty())
	{
		Pipe cur = Q.front(), next;
		int cur_r = cur.head.first;
		int cur_c = cur.head.second;
		cur_pipe_dir = pipe_dir(cur);

		Q.pop();
		count[cur_r][cur_c]++;

		// -방향으로 움직였을 때의 경우
		if (cur_pipe_dir == 0 || cur_pipe_dir == 1)
		{
			next = move_pipe(cur, N, 0);
			// 만약 움직일 수 있다고 판단이 되면 queue에 push
			if (!is_same_pipe(cur, next) && room[next.head.first][next.head.second] == 0)
			{
				Q.push(next);
			}
		}
		// \방향으로 움직였을 때의 경우
		if (cur_pipe_dir == 0 || cur_pipe_dir == 1 || cur_pipe_dir == 2)
		{
			next = move_pipe(cur, N, 1);
			if (!is_same_pipe(cur, next) && room[next.head.first][next.head.second] == 0 && room[next.tail.first + 1][next.tail.second] == 0 && room[next.tail.first][next.tail.second + 1] == 0)
			{
				Q.push(next);
			}
		}
		// |방향으로 움직였을 때의 경우
		if (cur_pipe_dir == 1 || cur_pipe_dir == 2)
		{
			next = move_pipe(cur, N, 2);
			if (!is_same_pipe(cur, next) && room[next.head.first][next.head.second] == 0)
			{
				Q.push(next);
			}
		}
	}

	cout << count[N][N];

	return 0;
}
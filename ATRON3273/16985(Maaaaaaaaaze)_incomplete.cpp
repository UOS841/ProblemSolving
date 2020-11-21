#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> plate;
typedef struct coordinate
{
	int x;
	int y;
	int z;
} Location;

static int dx[6] = { 0, 0, 0, 0, 1, -1 };
static int dy[6] = { 0, 0, 1, -1, 0, 0 };
static int dz[6] = { 1, -1, 0, 0, 0, 0 };

// cube의 한 plate 입력 및 생성
plate make_plate()
{
	vector<vector<int>> p(5, vector<int>(5));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> p[i][j];
		}
	}
	return p;
}

// 만들어진 cube의 최단경로 거리 연산(BFS)
int find_shortest_distance(plate cube[])
{
	queue<Location> Queue;
	// 여기에 cube의 최단경로를 구하기 위해 각 좌표에 대응하는 거리값 정보를 저장, -1로 초기화
	vector<plate> distance(5, plate(5, vector<int>(5, -1)));

	// queue에 초기 좌표 (0, 0, 0) push
	Queue.push({ 0, 0, 0 });
	distance[0][0][0] = 0;

	while (!Queue.empty())
	{
		// current는 queue에서 pop한 Location
		Location current;
		current.x = Queue.front().x;
		current.y = Queue.front().y;
		current.z = Queue.front().z;
		Queue.pop();
		/*
		cout << "distance\n";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					cout << distance[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}*/

		// 만약 current가 cube의 마지막 탈출구라면 거리값 return
		if (current.x == 4 && current.y == 4 && current.z == 4)
		{
			return distance[current.x][current.y][current.z];
		}
		
		// current 위치에서 상, 하, 좌, 우, 전, 후로 갈 수 있는 경로 탐색
		for (int i = 0; i < 6; i++)
		{
			// moved는 current에서 어디론가 움직였을 때의 좌표
			Location moved{ current.x + dx[i], current.y + dy[i], current.z + dz[i] };

			// 만약 이동할 곳의 좌표가 큐브를 벗어난 곳이라면 무시
			if (moved.x < 0 || moved.y < 0 || moved.z < 0 || moved.x > 4 || moved.y > 4 || moved.z > 4)
			{
				continue;
			}
			else
			{
				// 만약 moved 좌표가 아직 방문 안 했고 갈 수 있는 공간이라면 queue에 push
				// moved 위치까지의 최단경로는 distance[current] + 1
				if (cube[moved.x][moved.y][moved.z] == 1 && distance[moved.x][moved.y][moved.z] == -1)
				{
					distance[moved.x][moved.y][moved.z] = distance[current.x][current.y][current.z] + 1;
					Queue.push(moved);
				}
			}
		}
	}
	return -1;
}

// 만들어진 cube의 양 끝 좌표가 통과할 수 있는지 판별
bool find_play_possible(plate cube[])
{
	if (cube[0][0][0] == 1 && cube[4][4][4] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// plate 회전 함수
plate rotate(plate p, int rotate)
{
	if (rotate != 0)
	{
		plate temp(5, vector<int>(5));

		// 시계방향으로 90도 회전을 rotate번 반복
		for (int n = 0; n < rotate; n++)
		{
			// p를 회전시킨 결과를 temp에 저장
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					temp[j][4 - i] = p[i][j];
				}
			}

			// temp를 p에 덮어씌움
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					p[i][j] = temp[i][j];
				}
			}
		}
	}
	return p;
}

void shuffle_plate(plate cube[])
{
	
}

int main()
{
	plate cube[5];
	int result = 200;
	for (int i = 0; i < 5; i++)
	{
		cube[i] = make_plate();
	}

	for (int p0 = 0; p0 < 4; p0++)
	{
		for (int p1 = 0; p1 < 4; p1++)
		{
			for (int p2 = 0; p2 < 4; p2++)
			{
				for (int p3 = 0; p3 < 4; p3++)
				{
					for (int p4 = 0; p4 < 4; p4++)
					{
						plate clone[5];
						vector<int> plate_rotate{ p0, p1, p2, p3, p4 };
						
						for (int i = 0; i < 5; i++)
						{
							clone[i] = rotate(cube[i], plate_rotate[i]);
						}

						if (find_play_possible(clone) == true)
						{
							int tmp = find_shortest_distance(clone);
							if (tmp != -1 && result > tmp)
							{
								result = tmp;
							}
						}
					}
				}
			}
		}
	}
	if (result == 200)
	{
		result = -1;
	}
	cout << result;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> path(201, vector<int>());
vector<bool> visited(201, false);

bool find_path(int start, int end)
{
	bool is_possible = false;

	for (int i = 0; i < path[start].size(); i++)
	{
		// 만약 start에서 end로 갈 수 있다면 true
		if (path[start][i] == end)
		{
			is_possible = true;
			break;
		}
	}

	if (is_possible)
	{
		return is_possible;
	}
	else
	{
		for (int i = 0; i < path[start].size(); i++)
		{
			// 만약 경로 탐색 중 거친 지역이라면 넘김
			if (visited[path[start][i]] == false)
			{
				visited[path[start][i]] = true;
			}
			else
			{
				continue;
			}

			// 만약 start로부터 갈 수 있는 지점에서 end로 갈 수 있는 경로가 있다면
			// 해당 경로로 갈 수 있다고 저장, true 반환
			if (find_path(path[start][i], end))
			{
				path[start].push_back(end);
				path[end].push_back(start);
				is_possible = true;
				break;
			}
		}
	}

	// start에서 end로 결국 못 가면 false 출력
	return is_possible;
}

int main()
{
	int N, M;
	bool result = true;
	cin >> N;
	cin >> M;

	vector<int> plan(M);

	// 지역 연결 정보 입력
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				path[i].push_back(j);
			}
		}
	}

	// 여행 순서 입력
	for (int i = 0; i < M; i++)
	{
		cin >> plan[i];
	}

	// 여행 경로를 따라 탐색
	for (int i = 0; i < M - 1; i++)
	{
		// 매번 탐색 시 visited 벡터 false로 초기화
		visited.assign(201, false);

		// 만약 출발지와 도착지가 같다면 그대로 넘김
		if (plan[i] == plan[i + 1])
		{
			continue;
		}
		// 만약 출발지에서 도착지로 갈 수 없다면
		// result를 false로 설정, break
		else if (!find_path(plan[i], plan[i + 1]))
		{
			result = false;
			break;
		}
	}

	// 결과 출력
	if (result)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
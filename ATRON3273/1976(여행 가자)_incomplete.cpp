#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> path(201, vector<int>());
vector<bool> visited(201, false);

bool find_path(int start, int end)
{
	bool is_possible = false;

	cout << "start function " << start << " " << end << endl;
	for (int i = 0; i < path[start].size(); i++)
	{
		// 만약 start에서 end로 갈 수 있다면 true
		if (path[start][i] == end)
		{
			cout << "find : " << start << "->" << end << endl;
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
				cout << "find : " << start << "->" << path[start][i] << "->" << end << endl;

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

	for (int i = 0; i < M - 1; i++)
	{
		visited.resize(201, false);
		cout << "current : " << plan[i] << " " << plan[i + 1] << endl;
		if (!find_path(plan[i], plan[i + 1]))
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
#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 100000000

using namespace std;

int main()
{
	int n, m;
	cin >> n;															// 여기에 도시 갯수 입력
	cin >> m;															// 여기에 버스 갯수 입력

	int map[MAX][MAX];													// 여기에 각 도시 간 버스 비용 입력

	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;											// 같은 도시 내 이동 비용 0
			}
			else
			{
				map[i][j] = INF;										// 버스 이동 비용 INF로 초기화
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		if (map[from][to] > cost)
		{
			map[from][to] = cost;										// from -> to의 비용 cost 정보 저장
		}
	}

	// 플로이드 와셜 알고리즘
	for (int via = 1; via <= n; via++)									// via 도시를 경유하는 경우 탐색
	{
		for (int start = 1; start <= n; start++)						// start 도시에서
		{
			for (int end = 1; end <= n; end++)							// end 도시로 가는 버스 노선 중
			{
				if (map[start][end] > map[start][via] + map[via][end])	// start -> end로 가는 직빵 노선보다
				{														// start -> via -> end로 경유해서 가는 노선이 더 빠르면
					map[start][end] = map[start][via] + map[via][end];	// map[start][end]의 비용 갱신
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == INF)										// 만약 i -> j의 정보가 갱신되지 않았다면
			{															// 해당 도시 간 노선이 존재하지 않음
				cout << "0 ";											// 0 출력
			}
			else
			{
				cout << map[i][j] << " ";								// i -> j의 비용 출력
			}
		}
		cout << "\n";
	}
}
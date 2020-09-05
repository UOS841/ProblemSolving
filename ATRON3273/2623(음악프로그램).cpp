#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;										// N, M 입력

	vector<int> indegree(N + 1);						// 여기에 진입차수 기록
	vector<int> v[1001];								// 여기에 해당 정점에서 나가는 정점 기록
	vector<int> list(N);								// 여기에 가수들 출연 순서 차례로 기록
	int cur = 0;										// vector list에 들어간 가수의 수 기록
	queue<int> tmp_queue;								// 위상정렬 연산을 위한 큐

	// 데이터 입력
	for (int i = 0; i < M; i++)							// M번의 케이스 입력
	{
		int num;
		cin >> num;										// 각 케이스의 가수 수 입력

		int prev, next;
		for (int j = 0; j < num; j++)					// 가수 수만큼 입력
		{
			if (j == 0)									// 해당 케이스에서 제일 처음 입력하는 경우
			{
				cin >> next;							// 일단 입력값을 next에 입력
				continue;
			}
			else										// 해당 케이스에서 두 번째 이후 입력하는 경우
			{
				prev = next;							// 현재 next 값을 prev에 넣고
				cin >> next;							// next에 새로 값을 입력

				v[prev].push_back(next);				// 그 후 정점 prev에서 나가는 정점 next를 기록
				indegree[next]++;						// next 정점의 차수 증가
			}
		}
	}

	// 차수가 0인 정점 큐에 push
	for (int i = 1; i <= N; i++)						// 정점 N개의 차수를 검사
	{
		if (indegree[i] == 0)							// 해당 정점의 차수가 0이면
		{
			tmp_queue.push(i);							// 큐에 push
		}
	}

	// 출연 순서를 list에 넣는 과정 
	while (!tmp_queue.empty())							// 큐가 빌 때까지 반복
	{
		int cur_artist = tmp_queue.front();				// 큐의 맨 앞 정점을 cur_artist로 지정
		list[cur++] = cur_artist;						// cur_artist를 list에 넣고 cur 1 증가
		tmp_queue.pop();								// 그 후 큐에 있는 값 pop

		for (int i = 0; i < v[cur_artist].size(); i++)	// pop한 정점의 다음 정점들을 탐색
		{
			int next_artist = v[cur_artist][i];			// 해당 정점을 next_artist로 지정
			indegree[next_artist]--;					// 정점 next_artist와 앞서 pop한 cur_artist 정점과의 간선 제거, 차수 1 감소

			if (indegree[next_artist] == 0)				// 만약 next_artist 정점의 차수가 0이면
			{
				tmp_queue.push(next_artist);			// 큐에 next_artist push
			}
		}
	}

	// list 출력
	if (cur == N)										// 만약 모든 정점이 모두 탐색되어
	{													// list에 들어갔다면 cur == N
		for (int i = 0; i < N; i++)
		{
			cout << list[i] << endl;
		}
	}
	else
	{
		cout << 0 << endl;								// 그렇치 않은 경우 0 출력
	}

	return 0;
}
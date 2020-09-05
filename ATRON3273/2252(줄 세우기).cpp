#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	int front, back;							// 비교값 변수
	queue<int> cur;								// 결과값 출력을 위한 큐

	cin >> N >> M;								// N, M 값 입력

	vector<int> indegree(N + 1);				// 여기에 각 정점의 진입차수 기록
	vector<int> v[32001];						// 여기에 각 정점의 다음 차수 정점들을 기록

	for (int i = 0; i < M; i++)
	{
		cin >> front >> back;					// 비교한 값 M번 입력

		v[front].push_back(back);				// 정점의 다음 차수 정점 번호 기록
		indegree[back]++;						// 그리고 그 정점의 차수 하나 증가
	}

	// 차수가 0인 정점부터 큐에 push
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)					// 진입차수가 0이면
		{
			cur.push(i);						// 큐에 해당 노드 push
		}
	}

	// 큐에 있는 값을 차례로 출력
	while (!cur.empty())						// 큐가 빌 때까지 반복
	{
		int out = cur.front();					// 큐의 맨 앞에 있는 값을 out으로 지정
		cout << out << " ";						// out 값을 출력
		cur.pop();								// 그리고 해당 값을 큐에서 pop

		for (int i = 0; i < v[out].size(); i++)	// out의 정점에 저장되어 있던 다음 차수 정점 탐색
		{
			int next = v[out][i];				// out에서 나가는 정점을 next로 지정
			indegree[next]--;					// out과 연결된 간선 제거로 next 정점 차수 하나 감소

			if (indegree[next] == 0)			// 만약 next의 차수가 0이면
			{
				cur.push(next);					// next 값을 큐에 push
			}
		}
	}

	return 0;
}
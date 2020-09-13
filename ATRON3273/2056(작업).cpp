#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, answer = 0;																// 답 출력을 위한 answer 변수 선언
	cin >> N;																		// N 입력

	vector<int> each_time(N + 1);													// 여기에 해당 작업의 소요시간 입력
	vector<int> total_time(N + 1);													// 여기에 해당 작업 수행까지 걸린 누적 소요시간 입력
	vector<int> indegree(N + 1);													// 여기에 해당 작업의 차수 입력
	vector<int> next[10001];														// 여기에 해당 작업 수행 후 다음 작업 정보 저장
	queue<int> Q;																	// 위상정렬 탐색을 위한 큐 선언

	for (int i = 1; i <= N; i++)													// N개의 작업 정보 입력
	{
		int prev_task_num;															// 해당 작업의 선행작업 갯수 입력을 위한 변수 선언

		cin >> each_time[i] >> prev_task_num;										// 작업 소요시간과 선행작업 갯수 입력
		total_time[i] = each_time[i];												// each_time 내용을 total_time 벡터에 복제

		for (int j = 0; j < prev_task_num; j++)										// 각 작업의 선행작업 갯수만큼 반복
		{
			int prev_task;															// 선행작업들을 변수 prev_task를 이용해 입력
			cin >> prev_task;
			next[prev_task].push_back(i);											// 현재 입력한 선행작업의 다음 작업이 i번 작업
			indegree[i]++;															// 그러므로 i번 작업의 후 차수 증가
		}
	}

	for (int i = 1; i <= N; i++)													// N개의 작업 차수 탐색
	{
		if (indegree[i] == 0)														// 해당 작업의 차수가 0이면
		{
			Q.push(i);																// 큐에 push
		}
	}

	while (!Q.empty())																// 큐에 추가되는 작업 없이 다 빌 때까지 반복
	{
		int cur = Q.front();														// cur에 현재 큐의 맨 앞 작업 지정
		Q.pop();																	// 그리고 pop

		for (int i = 0; i < next[cur].size(); i++)									// 현재 작업 cur의 다음 작업들 탐색
		{
			int next_job = next[cur][i];											// cur의 다음 작업들을 next_job에 지정

			if (total_time[next_job] < total_time[cur] + each_time[next_job])		// cur까지 수행한 후 next_job을 수행한 총 시간이
			{																		// 다른 선행작업을 한 후 next_job을 시행했을 때 소요되는 시간보다 큰 것은
				total_time[next_job] = total_time[cur] + each_time[next_job];		// cur를 거쳐 next_job까지 수행하기 위해서 시간이 더 필요하단 의미
			}																		// 만약 그렇지 않다면 그 전에 기록된 next_job의 시간 안에 cur의 선행작업을 완료할 수 있음

			indegree[next_job]--;													// next_job의 차수 1 감소
			if (indegree[next_job] == 0)											// 만약 그것의 차수가 0이면
			{
				Q.push(next_job);													// 큐에 push
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (answer < total_time[i])
		{
			answer = total_time[i];													// total_time에서 최댓값 출력
		}
	}

	cout << answer;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, w, L;
	cin >> n >> w >> L;
	vector<int> truck(n);
	for (int i = 0; i < n; i++)
	{
		cin >> truck[i];
	}

	int front = 0, back = -1;
	int cur_weight = 0, time = 0;
	vector<int> start_time(n);
	vector<int> end_time(n);

	start_time[0] = 1;
	end_time[0] = start_time[0] + w;

	while (true)
	{
		time++;
		// cout << "t : " << time << endl;

		// 맨 앞의 트럭이 다리를 건넌 시간일 때
		if (time >= end_time[front])
		{
			// cout << cur_weight << " | " << front << " out" << endl;
			// 뒤따라오는 트럭을 선두로 놓음
			cur_weight -= truck[front];
			front++;
		}

		// 대기하고 있는 트럭이 있고
		// 그 트럭들 중 맨 앞의 트럭을 다리에 올렸을 때 다리가 버틸 수 있다면
		if (back < n - 1 && cur_weight + truck[back + 1] <= L)
		{
			// 맨 뒤의 트럭 정보를 추가
			back++;
			start_time[back] = time;
			end_time[back] = time + w;
			cur_weight += truck[back];

			// cout << cur_weight << " | " << back << " in" << endl;
		}

		// 다리를 건너는 트럭들 중 맨 뒤의 트럭이 마지막 트럭이면
		if (back == n - 1)
		{
			// 더 계산할 필요 없으니 while문 break
			break;
		}
	}

	cout << end_time[n - 1];

	return 0;
}
#define MAX 200000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> get_all_button_num(int N)
{
	int num = (1 << N) - 1;
	int count = N;

	return make_pair(num, count);
}

pair<int, int> get_odd_button_num(int N)
{
	int num = 0, count = 0;
	for (int i = 1; i <= N; i += 2)
	{
		num = (num << 2) + 1;
		count++;
	}

	return make_pair(num, count);
}

pair<int, int> get_even_button_num(int N)
{
	int num = 0, count = 0;
	for (int i = 2; i <= N; i += 2)
	{
		num = (num << 2) + 2;
		count++;
	}

	return make_pair(num, count);
}

pair<int, int> get_mod3_1_button_num(int N)
{
	int num = 0, count = 0;
	for (int i = 1; i <= N; i += 3)
	{
		num = (num << 3) + 1;
		count++;
	}

	return make_pair(num, count);
}

int get_case_count(int N, int m)
{
	int case_count = 4;
	vector<pair<int, int>> num_count(case_count);
	num_count[0] = get_all_button_num(N);
	num_count[1] = get_odd_button_num(N);
	num_count[2] = get_even_button_num(N);
	num_count[3] = get_mod3_1_button_num(N);

	vector<int> spended_time((1 << N), MAX);
	queue<int> q;

	q.push(0);
	spended_time[0] = 0;
	int count = 1;

	while (!q.empty())
	{
		int cur_case = q.front();
		q.pop();

		for (int i = 0; i < case_count; i++)
		{
			int next_case = cur_case ^ num_count[i].first;
			int next_time = num_count[i].second;

			int time = spended_time[cur_case] + next_time;
			if (spended_time[next_case] > time && time <= m)
			{
				spended_time[next_case] = time;
				q.push(next_case);
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int N, m;
	cin >> N >> m;

	cout << get_case_count(N, m);
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

#define MAX 501
#define INF 100000000

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> map[MAX];
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		map[A].push_back(make_pair(B, C));
	}

	vector<long long> time(N + 1, INF);
	time[1] = 0;
	bool cycle = false;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < map[j].size(); k++)
			{
				int cur = map[j][k].first;
				int cur_time = map[j][k].second;

				if (time[j] != INF && j != cur && time[cur] > time[j] + cur_time)
				{
					time[cur] = time[j] + cur_time;
					if (i == N)
					{
						cycle = true;
					}
				}
			}
		}
	}

	if (cycle == true)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (time[i] == INF)
			{
				cout << "-1\n";
			}
			else
			{
				cout << time[i] << "\n";
			}
		}
	}

	return 0;
}
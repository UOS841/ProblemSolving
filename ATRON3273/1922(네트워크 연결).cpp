#define INF 100000

#include <iostream>
#include <vector>

using namespace std;

int find_lowest_path_cost(vector<vector<pair<int, int>>> network)
{
	int num_computer = network.size() - 1;
	vector<bool> checked(num_computer + 1, false);

	checked[1] = true;
	int cur_connected_computer_num = 1;

	int total_cost = 0;
	// 모든 컴퓨터가 연결될 때까지 반복
	while (cur_connected_computer_num < num_computer)
	{
		int candidate_com = 0, min_cost = INF;

		// 현재 연결된 컴퓨터 내에서 탐색
		for (int com = 1; com < checked.size(); com++)
		{
			if (!checked[com])
			{
				continue;
			}

			// 현재 탐색 중인 컴퓨터와 연결된 컴퓨터 경로 비용 계산
			for (int i = 0; i < network[com].size(); i++)
			{
				int next_com = network[com][i].first;
				int cost = network[com][i].second;

				if (!checked[next_com] && min_cost > cost)
				{
					candidate_com = next_com;
					min_cost = cost;
				}
			}
		}

		// 연결할 컴퓨터를 발견하면 정보를 저장
		if (candidate_com != 0)
		{
			checked[candidate_com] = true;
			total_cost += min_cost;
			cur_connected_computer_num++;
		}
	}

	return total_cost;
}

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	vector<vector<pair<int, int>>> network(N + 1);
	for(int i = 0; i < M; i++)
	{
		int computer1, computer2, cost;
		cin >> computer1 >> computer2 >> cost;
		network[computer1].push_back(make_pair(computer2, cost));
		network[computer2].push_back(make_pair(computer1, cost));
	}

	cout << find_lowest_path_cost(network) << endl;
}
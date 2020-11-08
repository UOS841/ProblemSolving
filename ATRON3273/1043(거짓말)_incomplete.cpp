#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int head[51];

int find_head(int x)
{
	if (x = head[x])
	{
		return x;
	}
	else
	{
		return head[x] = find_head(head[x]);
	}
}

void merge(int x, int y)
{
	x = find_head(x);
	y = find_head(y);

	if (x != y)
	{
		head[y] = x;
	}
}

int main()
{
	int N, M, know_truth, result;
	// N, M 입력
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		head[i] = i;
	}

	// 진실을 아는 사람의 정보 입력
	cin >> know_truth;
	vector<int> know_truth_people(know_truth);
	for (int i = 0; i < know_truth; i++)
	{
		cin >> know_truth_people[i];
	}

	// 파티 참석자 input 입력
	vector<vector<int>> attendance_info(M, vector<int>());
	for (int party = 0; party < M; party++)
	{
		int num_attendance;
		cin >> num_attendance;

		attendance_info[party].resize(num_attendance);
		for (int i = 0; i < num_attendance; i++)
		{
			cin >> attendance_info[party][i];
		}
	}

	// 모든 사람들이 진실을 모를 때 파티 수 출력
	if (know_truth == 0)
	{
		result = M;
	}
	else
	{
		// 파티의 첫 참석자의 head를 확인하고, 그 후의 참석자들을 해당 head로 merge
		for (int party = 0; party < M; party++)
		{
			if (attendance_info[party].size() == 0)
			{
				continue;
			}
			else
			{
				int tmp_head = find_head(attendance_info[party][0]);
				for (int i = 1; i < attendance_info[party].size(); i++)
				{
					merge(tmp_head, attendance_info[party][i]);
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			cout << head[i] << " ";
		}
		for (int i = 1; i <= N; i++)
		{
			head[i] = find_head(head[i]);
			cout << head[i] << " ";
		}


		// 파티의 첫 참석자의 head가 진실을 아는 사람의 head와 같으면 result--
		result = M;
		for (int party = 0; party < M; party++)
		{
			if (attendance_info[party].size() == 0)
			{
				continue;
			}
			else
			{
				for (int i = 0; i < know_truth_people.size(); i++)
				{
					if (head[know_truth_people[i]] == head[attendance_info[party][0]])
					{
						result--;
						break;
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}
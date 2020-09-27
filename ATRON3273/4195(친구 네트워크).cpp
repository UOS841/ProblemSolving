#include <iostream>
#include <vector>
#include <map>

using namespace std;

int head[100000];
int friend_num[100000];

int find(int x)
{
	if (head[x] == x)
	{
		return x;
	}
	else
	{
		return head[x] = find(head[x]);
	}
}

void merge(int n1, int n2)
{
	int head_n1 = find(n1);
	int head_n2 = find(n2);

	if (friend_num[head_n1] < friend_num[head_n2])
	{
		head[head_n1] = head_n2;
		friend_num[head_n2] += friend_num[head_n1];
		friend_num[head_n1] = 0;
	}
	else
	{
		head[head_n2] = head_n1;
		friend_num[head_n1] += friend_num[head_n2];
		friend_num[head_n2] = 0;
	}
	return 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int test_case, F;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		map<string, int> network;
		for (int j = 0; j < 100000; j++)
		{
			head[j] = j;
			friend_num[j] = 1;
		}

		cin >> F;
		int id = 0;
		for (int j = 0; j < F; j++)
		{
			string f1, f2;
			cin >> f1 >> f2;
			
			if (network.count(f1) == 0)
			{
				network[f1] = id++;
			}
			if (network.count(f2) == 0)
			{
				network[f2] = id++;
			}

			int head_f1 = find(network[f1]);
			int head_f2 = find(network[f2]);

			if (head_f1 == head_f2)
			{
				cout << friend_num[head_f1] << "\n";
			}
			else
			{
				merge(network[f1], network[f2]);
				cout << (friend_num[head_f1] ? friend_num[head_f1] : friend_num[head_f2]) << "\n";
			}
		}
	}
}
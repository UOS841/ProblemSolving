#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int eliminated = 0;
	int cur = 0;
	vector<int> table(N, 1);
	vector<int> died(N);

	while (eliminated < N)
	{
		for (int i = 1; i <= K;)
		{
			if (table[cur] == 1 && i == K)
			{
				break;
			}
			if (table[cur] == 1)
			{
				cur = (cur + 1) % N;
				i++;
			}
			else if (table[cur] == 0)
			{
				cur = (cur + 1) % N;
			}

		}
		table[cur] = 0;
		died[eliminated] = cur + 1;
		cur = (cur + 1) % N;
		eliminated++;
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
		{
			cout << died[i] << ">";
		}
		else
		{
			cout << died[i] << ", ";
		}
	}
}
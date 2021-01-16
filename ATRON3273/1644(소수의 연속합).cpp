#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N, count = 0;
	cin >> N;

	vector<bool> prime(N + 1, true);
	vector<int> prime_list;

	for (int i = 2; i <= (int)sqrt(N); i++)
	{
		if (prime[i] == false)
		{
			continue;
		}
		for (int j = i + i; j <= N; j += i)
		{
			prime[j] = false;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (prime[i])
		{
			prime_list.push_back(i);
		}
	}

	int head = 0, tail = 0;
	while (head < prime_list.size() && tail < prime_list.size())
	{
		int sum = 0;
		for (int i = tail; i <= head; i++)
		{
			sum += prime_list[i];
		}

		if (sum > N)
		{
			tail++;
		}
		else if (sum < N)
		{
			head++;
		}
		else
		{
			count++;
			tail++;
			head++;
		}
	}
	cout << count;

	return 0;
}
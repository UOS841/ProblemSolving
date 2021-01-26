#define MAX 100000

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, S, length = MAX;
	cin >> N >> S;
	int sequence[MAX];

	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}

	int head = 0, tail = 0;
	int cur_sum = sequence[0];

	while (tail <= head && head < N)
	{
		if (cur_sum > S)
		{
			length = min(length, head - tail + 1);
			cur_sum -= sequence[tail++];
		}
		else if (cur_sum == S)
		{
			length = min(length, head - tail + 1);
			cur_sum += sequence[++head];
		}
		else
		{
			cur_sum += sequence[++head];
		}
	}

	if (length == MAX)
	{
		length = 0;
	}

	cout << length;

	return 0;
}
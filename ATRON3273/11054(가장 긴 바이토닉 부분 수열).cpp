#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> dp_asc(N, 1);	// 오름차순
	vector<int> dp_des(N, 1);	// 내림차순
	vector<int> sum_dp(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				if (dp_asc[i] < dp_asc[j] + 1)
				{
					dp_asc[i] = dp_asc[j] + 1;
				}
			}
		}
	}
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (A[i] > A[j])
			{
				if (dp_des[i] < dp_des[j] + 1)
				{
					dp_des[i] = dp_des[j] + 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		sum_dp[i] = dp_asc[i] + dp_des[i];
	}

	cout << *max_element(sum_dp.begin(), sum_dp.end()) - 1;

	return 0;
}
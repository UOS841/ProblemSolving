#define MIN -10000000
#define MAX 10000000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, max_sum = MIN;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	vector<int> Lside_dp(N);
	vector<int> Rside_dp(N);
	int cur_min = MAX;
	int cur_max = MIN;

	Lside_dp[0] = MIN;
	Rside_dp[N - 1] = MIN;

	for (int i = 1; i < N - 1; i++)
	{
		Lside_dp[i] = max(A[i] - cur_min, Lside_dp[i - 1]);
		cur_min = min(cur_min, A[i]);
	}
	for (int i = N - 2; i >= 2; i--)
	{
		Rside_dp[i] = max(cur_max - A[i], Rside_dp[i + 1]);
		cur_max = max(cur_max, A[i]);
	}

	/*
	for (int i = 0; i < N - 1; i++)
	{
		cout << Lside_dp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N - 1; i++)
	{
		cout << Rside_dp[i] << " ";
	}
	cout << endl;
	*/

	for (int i = 1; i < N - 1; i++)
	{
		int Lmax = Lside_dp[i];
		int Rmax = Rside_dp[i];

		max_sum = max(max_sum, Lmax + Rmax);
	}


	cout << max_sum;

	return 0;
}
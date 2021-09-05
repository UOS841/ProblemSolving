#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> calc_lotto_case()
{
	// 이 이차원 벡터의 (n, m) 자리에 들어가는 숫자는
	// 로또의 n번째 자리에 1 ~ m 숫자가 들어가는 로또의 경우의 수를 저장
	vector<vector<long long>> lotto(11, vector<long long>(2001, 0));

	int j_start = 1;

	for (int i = 1; i <= 10; i++)
	{
		for (int j = j_start; j <= 2000; j++)
		{
			if (i == 1)
			{
				// 로또의 첫 번째 자리에 j 이하의 숫자가 들어갈 수 있는 경우는
				// 1부터 j까지 총 j개 
				lotto[i][j] = j;
			}
			else
			{
				// 로또의 i번째 자리에 j 이하의 숫자가 들어갈 수 있는 경우의 수는 아래의 두 경우의 수를 합친 값
				// - 로또의 i번째 자리에 j - 1 이하의 숫자가 들어갈 수 있는 경우
				// - 로또의 i번째 자리에 j 숫자가 들어가는 경우(i - 1번째 자리에는 최대 j / 2만큼의 숫자가 들어갈 수 있음)
				lotto[i][j] = lotto[i][j - 1] + lotto[i - 1][j / 2];
			}
		}
		j_start *= 2;
	}

	return lotto;
}

long long get_lotto_count_num(vector<vector<long long>> lotto, int n, int m)
{
	return lotto[n][m];
}

int main()
{
	vector<vector<long long>> lotto = calc_lotto_case();

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n, m;
		cin >> n >> m;

		cout << get_lotto_count_num(lotto, n, m) << endl;
	}

	return 0;
}
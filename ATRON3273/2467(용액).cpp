#define MAX 2000000001

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> solution(N);
	for (int i = 0; i < N; i++)
	{
		cin >> solution[i];
	}

	int neutral = MAX;
	int alcal_solution = 0, acid_solution = N - 1;
	int p_alcal = 0, p_acid = N - 1;

	while (p_alcal < p_acid)
	{
		int combined_solution = solution[p_alcal] + solution[p_acid];

		// 전에 합친 용액보다 지금 합친 용액이 0에 근접할 경우 값 교체
		if (neutral > abs(combined_solution))
		{
			neutral = abs(combined_solution);
			alcal_solution = p_alcal;
			acid_solution = p_acid;
		}

		// 합친 용액의 특성이 0일 경우 break
		if (combined_solution == 0)
		{
			break;
		}
		// 합친 용액의 특성이 산성일 경우 좀 더 약한 산성 용액으로 교체
		else if (combined_solution > 0)
		{
			p_acid--;
		}
		// 합친 용액의 특성이 알칼리성일 경우 좀 더 약한 알칼리 용액으로 교체
		else
		{
			p_alcal++;
		}
	}

	cout << solution[alcal_solution] << " " << solution[acid_solution] << endl;
	return 0;
}
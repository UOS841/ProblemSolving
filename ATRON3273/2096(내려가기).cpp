#define INF 1000000

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, high = 0, low = INF;
	cin >> N;

	vector<int> line(3);
	vector<int> old_high_score(3, 0);
	vector<int> new_high_score(3, 0);
	vector<int> old_low_score(3, 0);
	vector<int> new_low_score(3, INF);

	for (int i = 0; i < N; i++)
	{
		cin >> line[0] >> line[1] >> line[2];

		for (int j = 0; j < 3; j++)			// i - 1번째 줄의 score
		{
			for (int k = 0; k < 3; k++)		// i번재 줄의 line
			{
				if (abs(j - k) > 1)
				{
					continue;
				}
				else
				{
					if (new_high_score[k] < old_high_score[j] + line[k])
					{
						new_high_score[k] = old_high_score[j] + line[k];
					}
					if (new_low_score[k] > old_low_score[j] + line[k])
					{
						new_low_score[k] = old_low_score[j] + line[k];
					}
				}
			}
		}
		
		for (int j = 0; j < 3; j++)
		{
			old_high_score[j] = new_high_score[j];
			new_high_score[j] = 0;
			old_low_score[j] = new_low_score[j];
			new_low_score[j] = INF;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (high < old_high_score[i])
		{
			high = old_high_score[i];
		}
		if (low > old_low_score[i])
		{
			low = old_low_score[i];
		}
	}
	cout << high << " " << low;

	return 0;
}
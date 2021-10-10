#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_max_line_num(vector<int>& line, int require_num)
{
	long long min = 1, max = *max_element(line.begin(), line.end());
	long long before_line_count = line.size();

	while (min <= max)
	{
		long long mid = (min + max) / 2;
		long long cut_count = 0;

		for (int i = 0; i < before_line_count; i++)
		{
			cut_count += line[i] / mid;
		}

		//cout << mid << " " << cut_count << " " << min << " " << max << endl;

		// 목표 갯수와 같거나 그보다 많이 자르는 경우
		if (cut_count >= require_num)
		{
			// 길이 상향
			min = mid + 1;
		}
		// 목표 갯수보다 적게 자르는 경우
		else
		{
			// 길이 하향
			max = mid - 1;
		}
	}

	return max;
}

int main()
{
	int K, N;
	cin >> K >> N;
	vector<int> line(K);
	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
	}

	cout << count_max_line_num(line, N);

	return 0;
}
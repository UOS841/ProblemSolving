#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K, remain, result = 0;
	cin >> N >> K;
	int num_2_times[27] = { 1 };
	
	int tmp = 1;
	for (int i = 1; i < 27; i++)
	{
		tmp *= 2;
		num_2_times[i] = tmp;
	}

	remain = N;
	for (int k = K; k > 0; k--)
	{
		int cur_max = 0;
		for (int i = 0; i < 27; i++)
		{
			if (remain - num_2_times[i] < 0)
			{
				remain -= cur_max;
				//cout << cur_max << " " << remain << endl;
				
				if (remain != 0 && k == 1)
				{
					result = cur_max - remain;
				}
				break;
			}
			else
			{
				cur_max = num_2_times[i];
			}
		}
	}

	cout << result;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

long long sum_vector_element(vector<long long> v, int start, int end)
{
	long long sum = 0;

	for (int i = start; i < end; i++)
	{
		sum += v[i];
	}

	return sum;
}

long long count_nondiminish_number(int n)
{
	vector<long long> attachable_num_count(10, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			attachable_num_count[j] = sum_vector_element(attachable_num_count, j, 10);
		}
	}

	return sum_vector_element(attachable_num_count, 0, 10);
}

int main()
{
	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> n;
		cout << count_nondiminish_number(n) << '\n';
	}
	return 0;
}
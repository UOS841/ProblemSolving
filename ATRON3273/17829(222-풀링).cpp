#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_2nd(int a, int b, int c, int d)
{
	int arr[4] = { a, b, c, d };
	sort(arr, arr + 4);

	return arr[2];
}

int pooling(vector<vector<int>> m)
{
	int len = m.size();
	int gap = 2;

	while (gap <= len)
	{
		for (int i = 0; i < len; i += gap)
		{
			for (int j = 0; j < len; j += gap)
			{
				m[i][j] = find_2nd(m[i][j], m[i][j + gap / 2], m[i + gap / 2][j], m[i + gap / 2][j + gap / 2]);
			}
		}
		gap *= 2;
	}
	return m[0][0];
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N)) ;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << pooling(matrix);

	return 0;
}
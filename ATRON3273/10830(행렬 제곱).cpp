#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] % 1000 << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> times(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int size)
{
	vector<vector<int>> calc_matrix(size, vector<int>(size, 0));

	for (int i = 0; i < matrix1.size(); i++)
	{
		for (int j = 0; j < matrix2[i].size(); j++)
		{
			for (int k = 0; k < size; k++)
			{
				calc_matrix[i][j] += (matrix1[i][k] * matrix2[k][j]);
			}
			calc_matrix[i][j] %= 1000;
		}
	}

	return calc_matrix;
}

vector<vector<int>> square(vector<vector<int>> matrix, int size)
{
	return times(matrix, matrix, size);
}

vector<vector<int>> calc(vector<vector<int>> matrix, int size, unsigned long long power)
{
	if (power == 1)
	{
		return matrix;
	}
	else if (power == 2)
	{
		return square(matrix, size);
	}
	else if (power % 2 == 0)
	{
		return square(calc(matrix, size, power / 2), size);
	}
	else
	{
		vector<vector<int>> matrix1 = square(calc(matrix, size, power / 2), size);
		vector<vector<int>> matrix2 = matrix;
		return times(matrix1, matrix2, size);
	}
}

int main()
{
	int N;
	unsigned long long B;
	cin >> N;
	cin >> B;
	vector<vector<int>> matrix(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	vector<vector<int>> result = calc(matrix, N, B);

	print_matrix(result);
	return 0;
}
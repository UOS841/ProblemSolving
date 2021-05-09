#define MAX 15

#include <iostream>
#include <vector>

using namespace std;

int path[MAX][MAX];

void build_path_num()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i == 0 || j == 0)
			{
				path[i][j] = 1;
			}
			else
			{
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
	}
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	build_path_num();

	if (K == 0)
	{
		cout << path[N - 1][M - 1] << endl;
	}
	else
	{
		int check_r = K / M;
		int check_c = K % M - 1;

		int check_point_path_num = path[check_r][check_c];
		int final_point_path_num = path[N - check_r - 1][M - check_c - 1];

		cout << check_point_path_num * final_point_path_num << endl;
	}
	return 0;
}
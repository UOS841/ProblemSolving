#include <iostream>
#include <vector>

using namespace std;

int canvas[500][500];
bool visited[500][500];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int DFSarea(int x, int y, int cur_area, int height, int width)
{
	if (canvas[y][x] == 1 && visited[y][x] == false)
	{
		visited[y][x] = true;
		cur_area++;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < height)
			{
				cur_area = DFSarea(next_x, next_y, cur_area, height, width);
			}
		}
	}
	return cur_area;
}

int main()
{
	int n, m, max_area = 0, count = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> canvas[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (canvas[i][j] == 1 && visited[i][j] == false)
			{
				count++;

				int area = DFSarea(j, i, 0, n, m);
				if (max_area < area)
				{
					max_area = area;
				}
			}
		}
	}

	cout << count << endl;
	cout << max_area << endl;

	return 0;
}
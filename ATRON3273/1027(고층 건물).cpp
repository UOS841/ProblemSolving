#include <iostream>
#include <vector>

using namespace std;

typedef struct Building
{
	long long loc;
	long long height;
} Building;

long long cross_product(pair<long long, long long> a, pair<long long, long long> b)
{
	return a.first * b.second - a.second * b.first;
}

int main()
{
	int N, max_visible = 0;
	cin >> N;

	vector<Building> building(N);
	vector<vector<bool>> visible(N, vector<bool>(N, false));
	
	for (int i = 0; i < N; i++)
	{
		building[i].loc = i;
		cin >> building[i].height;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			pair<long long, long long> x1 = { building[j].loc - building[i].loc, building[j].height - building[i].height };
			
			if (x1.first == 1)
			{
				visible[i][j] = true;
				visible[j][i] = true;
			}
			else
			{
				bool is_visible = true;
				for (int k = i + 1; k < j; k++)
				{
					pair<long long, long long> x2 = { building[k].loc - building[i].loc, building[k].height - building[i].height };
					long long cross = cross_product(x1, x2);

					if (cross >= 0)
					{
						is_visible = false;
						break;
					}
					else
					{
						continue;
					}
				}
				if (is_visible == true)
				{
					visible[i][j] = true;
					visible[j][i] = true;
				}
			}
		}
		int tmp = 0;
		for (int j = 0; j < N; j++)
		{
			if (visible[i][j] == true)
			{
				tmp++;
			}
		}

		if (max_visible < tmp)
		{
			max_visible = tmp;
		}
	}

	cout << max_visible;

	return 0;
}
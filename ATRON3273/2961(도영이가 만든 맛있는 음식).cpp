#define INF 2000000000

#include <iostream>
#include <vector>

using namespace std;

int get_sour_bitter_taste_diff(vector<pair<int, int>> ingredient)
{
	int ingredient_count = ingredient.size();
	int min = INF;

	for (int i = 1; i < (1 << ingredient_count); i++)
	{
		int sour = 1, bitter = 0;
		for (int j = 0; j < ingredient_count; j++)
		{
			if ((i & (1 << j)) != 0)
			{
				sour *= ingredient[j].first;
				bitter += ingredient[j].second;
			}
		}

		if (min > abs(sour - bitter))
		{
			min = abs(sour - bitter);
		}
		//cout << i << " | " << abs(sour - bitter) << " | " << sour << " " << bitter << endl;
	}

	return min;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> ingredient(N);

	for (int i = 0; i < N; i++)
	{
		cin >> ingredient[i].first >> ingredient[i].second;
	}

	cout << get_sour_bitter_taste_diff(ingredient);
	return 0;
}
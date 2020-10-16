#include <iostream>
#include <vector>

using namespace std;

typedef struct dot
{
	int x;
	int y;
} dot;

int main()
{
	vector<dot> D(3);
	double cross_product;
	for (int i = 0; i < 3; i++)
	{
		cin >> D[i].x >> D[i].y;
	}

	cross_product = (D[1].x - D[0].x) * (D[2].y - D[0].y) - (D[2].x - D[0].x) * (D[1].y - D[0].y);

	if (cross_product > 0)
	{
		cout << 1;
	}
	else if (cross_product == 0)
	{
		cout << 0;
	}
	else
	{
		cout << -1;
	}

	return 0;
}
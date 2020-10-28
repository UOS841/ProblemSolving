#include <iostream>

using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3, x, y;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	if (x1 == x2)
	{
		x = x3;
	}
	else if (x2 == x3)
	{
		x = x1;
	}
	else if (x3 == x1)
	{
		x = x2;
	}

	if (y1 == y2)
	{
		y = y3;
	}
	else if (y2 == y3)
	{
		y = y1;
	}
	else if (y3 == y1)
	{
		y = y2;
	}

	cout << x << " " << y;
}
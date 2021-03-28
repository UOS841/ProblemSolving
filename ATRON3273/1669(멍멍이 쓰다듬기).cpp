#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned int X, Y, diff, n = 1, answer;
	cin >> X >> Y;

	diff = Y - X;
	while (n * n < diff)
	{
		n++;
	}

	unsigned int determine_value = n * n - n;

	if (diff <= determine_value)
	{
		answer = 2 * n - 2;
	}
	else
	{
		answer = 2 * n - 1;
	}

	cout << answer;

	return 0;
}
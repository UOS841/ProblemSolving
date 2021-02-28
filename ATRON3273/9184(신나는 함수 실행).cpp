#include <iostream>
#include <vector>

using namespace std;

unsigned long long w[21][21][21];

void calc_w()
{
	for (int a = 0; a <= 20; a++)
	{
		for (int b = 0; b <= 20; b++)
		{
			for (int c = 0; c <= 20; c++)
			{
				if (a == 0 || b == 0 || c == 0)
				{
					w[a][b][c] = 1;
				}
				else if (a < b && b < c)
				{
					w[a][b][c] = w[a][b][c - 1] + w[a][b - 1][c - 1] - w[a][b - 1][c];
				}
				else
				{
					w[a][b][c] = w[a - 1][b][c] + w[a - 1][b - 1][c] + w[a - 1][b][c - 1] - w[a - 1][b - 1][c - 1];
				}
			}
		}
	}
}

int main()
{
	calc_w();

	while (true)
	{
		int a, b, c, answer;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}
		else
		{
			if (a <= 0 || b <= 0 || c <= 0)
			{
				answer = 1;
			}
			else if (a > 20 || b > 20 || c > 20)
			{
				answer = w[20][20][20];
			}
			else
			{
				answer = w[a][b][c];
			}
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << answer << endl;
	}

	return 0;
}
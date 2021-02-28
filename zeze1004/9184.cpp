#include <iostream>
using namespace std;

int a, b, c;
int output[21][21][21]; // a, b, c 중 하나가 20이 넘으면 w(20, 20, 20)이므로

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	else if (a < b && b < c)
	{
		if (output[a][b][c] != 0)
		{
			return output[a][b][c];
		}
		return output[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		if (output[a][b][c] != 0)
		{
			return output[a][b][c];
		}
		output[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	return output[a][b][c];
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
	return 0;
}

#include <iostream>

using namespace std;

int group[1000001];

int find(int x)
{
	if (group[x] == x)
	{
		return x;
	}
	else
	{
		group[x] = find(group[x]);
		return group[x];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		group[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int which, a, b;
		cin >> which >> a >> b;

		a = find(a);
		b = find(b);

		if (which == 0)
		{
			if (a != b)
			{
				group[b] = a;
			}
		}
		else if (which == 1)
		{
			if (a == b)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
	return 0;
}
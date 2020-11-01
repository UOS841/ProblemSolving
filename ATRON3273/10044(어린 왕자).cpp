#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int x1, y1, x2, y2, n, count = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;

			int d1 = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
			int d2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);

			if ((d1 < r * r && d2 > r * r) || (d1 > r * r && d2 < r* r))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
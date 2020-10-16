#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while (true)
	{
		long long len[3];
		cin >> len[0] >> len[1] >> len[2];

		if (len[0] == 0 && len[1] == 0 && len[2] == 0)
		{
			break;
		}

		sort(len, len + 3);

		if (len[2] * len[2] == len[0] * len[0] + len[1] * len[1])
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
	return 0;
}
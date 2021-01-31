#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;
int n, k, res;

bool dfs(int sum, int count)
{
	// cout << "start dfs(" << sum << ", " << count << ")" << endl;
	if (sum == n)
	{
		// cout << "- res : " << res << endl;
		res++;
	}
	else if (sum > n)
	{
		return false;
	}

	if (res == k)
	{
		return true;
	}

	for (int i = 1; i <= 3; i++)
	{
		// cout << "cnt " << count << " -> " << i << "?" << endl;

		if (sum + i <= n)
		{
			if (dfs(sum + i, count + 1) == true)
			{
				// cout << "add " << i << endl;
				seq.push_back(i);
				return true;
			}
		}
	}
	// cout << "end dfs(" << sum << ", " << count << ")" << endl;
	return false;
}

int main()
{
	// cin >> n >> k;

	dfs(0, 0);
	if (seq.size() == 0)
	{
		cout << -1;
	}
	else
	{
		for (int i = seq.size() - 1; i >= 0; i--)
		{
			if (i < seq.size() - 1)
			{
				cout << "+";
			}
			cout << seq[i];
		}
	}

	return 0;
}
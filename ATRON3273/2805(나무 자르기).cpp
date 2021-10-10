#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_min_height(vector<int>& tree, int M)
{
	sort(tree.begin(), tree.end());

	int answer = 0;
	int tree_count = tree.size();
	int left = 0, right = tree[tree_count - 1];

	while (left <= right)
	{
		long long sum = 0;
		int mid = (left + right) / 2;

		for (int i = 0; i < tree_count; i++)
		{
			int cut_len = tree[i] - mid;
			if (cut_len > 0)
			{
				sum += cut_len;
			}
		}
		if (sum < M)
		{
			right = mid - 1;
		}
		else
		{
			answer = mid;
			left = mid + 1;
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> tree;
	tree.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}

	cout << get_min_height(tree, M);

	return 0;
}
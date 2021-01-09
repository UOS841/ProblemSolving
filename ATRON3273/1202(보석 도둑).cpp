#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	long long total = 0;
	cin >> N >> K;
	vector<pair<int, int>> gem(N);
	vector<int> bag(K);

	for (int i = 0; i < N; i++)
	{
		//			weight			price
		cin >> gem[i].first >> gem[i].second;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}

	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;

	int g = 0;
	for (int b = 0; b < K; b++)
	{
		while (g < N && gem[g].first <= bag[b])
		{
			pq.push(gem[g++].second);
		}
		if (!pq.empty())
		{
			total += pq.top();
			pq.pop();
		}
	}
	cout << total;

	return 0;
}
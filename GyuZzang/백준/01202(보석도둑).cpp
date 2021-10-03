#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	vector<pair<int, int>> jewel; //{weight, cost}
	vector<int> C;
	long long res = 0;

	cin >> N >> K;
	jewel.resize(N);
	C.resize(K);

	for (int i = 0; i < N; i++) cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < K; i++) cin >> C[i];

	sort(jewel.begin(), jewel.end());
	//cout << jewel[0].second;
	sort(C.begin(), C.end());

	priority_queue<int> pq;

	int j = 0;
	for (int i = 0; i < K; i++) {
		for (; j < N && jewel[j].first <= C[i]; j++) 
			pq.push(jewel[j].second);
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res;
}

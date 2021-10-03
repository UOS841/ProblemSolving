#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	vector<vector<short>> related_city;
	vector<short> route;
	vector<bool> visited;
	queue<short> q;
	bool input;

	cin >> N >> M;
	related_city.resize(N);
	route.resize(M);
	visited.resize(N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) {
				related_city[i].push_back(j);

			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> route[i];
		route[i]--;
	}

	for (short i = 0; i < route.size()-1;i++) {
		queue<short> empty_Q;
		if (route[i] == route[i + 1]) continue;
		for (int j = 0; j < N; j++) {
			visited[j] = 0;
		}
		bool is_in = 0;

		visited[route[i]] = 1;
		q.push(route[i]);
		while (!q.empty()) {
			short now = q.front();
			q.pop();
			for (auto j : related_city[now]) {
				if (visited[j] == 1) continue;
				visited[j] = 1;
				if (j == route[i + 1]) {
					is_in = 1;
					q.swap(empty_Q);
					break;
				}
				else {
					q.push(j);
				}
			}
			//for 밖에서 isin 확인?
		}
		if (is_in == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int get_distance(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		vector<pair<pair<int, int>, int>> A; //A=[{{x,y},r},...]
		vector<int> visited;
		queue<int> q;

		int group_cnt=1;

		cin >> N;
		A.resize(N);
		visited.resize(N,0);

		for (int i = 0; i < N; i++) {
			cin >> A[i].first.first >> A[i].first.second >> A[i].second;
		}

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			q.push(i);

			//BFS
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				visited[now] = group_cnt;
				for (int j =0 ; j < N; j++) {
					if (visited[j]) continue;
					if (get_distance(A[now].first, A[j].first) <= A[now].second + A[j].second) {
						visited[j] = group_cnt;
						q.push(j);
					}
				}
			}

			//q is empty
			group_cnt++;
		}

		A.clear();
		visited.clear();
		cout << group_cnt - 1 << endl ;
	}
}
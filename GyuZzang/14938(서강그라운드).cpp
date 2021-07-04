#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define INF 16 //limit + 1

int main() {
	int n, m, r, //# of space, limit length of scope, # of road
		ans = 0;
	vector<int> n_items;
	vector<vector<int>> graph; //length

	cin >> n >> m >> r;

	graph.resize(n, vector<int>(n, INF));
	n_items.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> n_items[i];
	}

	while (r--) {
		int start, end, length;
		cin >> start >> end >> length;
		
		graph[start - 1][end - 1] = graph[end - 1][start - 1] = length;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[j][i] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int sum = n_items[i];
		for (int j = 0; j < n; j++) {
			if (graph[i][j] <= m) sum += n_items[j];
		}
		ans = max(ans, sum);
	}

	cout << ans;

}
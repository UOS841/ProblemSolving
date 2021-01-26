#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 51;

int main() {
	int n;
	vector<vector<int>> m;
	vector<int> level;
	vector<int> candidate;

	cin >> n;
	m.resize(n + 1, vector<int>(n + 1, 51));
	level.resize(n + 1);
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a < 0) break;
		m[a][b] = m[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (m[i][k] + m[k][j] < m[i][j]) {
					m[i][j] = m[j][i] = m[i][k] + m[k][j];
				}
			}
		}
	}

	int total_min = MAX;
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 1; j <= n; j++) {
			if (max < m[i][j]) max = m[i][j];
		}
		level[i] = max;
		if (total_min > max) total_min = max;
	}

	for (int i = 1; i <= n; i++) {
		if (level[i] == total_min) candidate.push_back(i);
	}
	sort(candidate.begin(), candidate.end());

	cout << total_min << " " << candidate.size() << endl;
	for (int i : candidate) cout << i << " ";
}
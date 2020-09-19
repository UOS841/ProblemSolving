#include <iostream>
#include <set>

using namespace std;

char map[1000][1000];
int  group[1000][1000];

int cnt = 1;
int dfs(int r, int c) {
	if (group[r][c] != -1)
		return group[r][c];
	group[r][c] = cnt;

	int nr = r;
	int nc = c;

	switch (map[r][c]) {
	case 'U': nr--; break;
	case 'D': nr++; break;
	case 'L': nc--; break;
	case 'R': nc++; break;
	}
	return group[r][c] = dfs(nr, nc);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	int N,	// # of rows
		M;	// # of cols
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0;c < M;c++) {
			cin >> map[r][c];
			group[r][c] = -1;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0;c < M;c++) {
			if (group[r][c] == -1) {
				dfs(r, c);
				cnt++;
			}
		}
	}

	set<int> set;
	for (int r = 0; r < N; r++) {
		for (int c = 0;c < M;c++) {
			set.insert(group[r][c]);
		}
	}
	cout << set.size();
	return 0;
}

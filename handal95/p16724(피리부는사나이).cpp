#include <iostream>
#include <set>

using namespace std;


char map[1000][1000];
int  group[1000][1000];

int group_cnt = 0;
int dfs(int r, int c) {
	if (group[r][c] != -1){
		group_cnt--;
		return group[r][c];
	}
	group[r][c] = group_cnt;

	int nr = r;
	int nc = c;

	switch (map[r][c]) {
	case 'U': nr--; break;
	case 'D': nr++; break;
	case 'L': nc--; break;
	case 'R': nc++; break;
	}

	int next_group = dfs(nr, nc);
	if (group[r][c] != next_group) {	
		group[r][c] = next_group;
		group_cnt--;
	}

	return group[r][c];
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
				group_cnt++;
				dfs(r, c);
			}
		}
	}

	cout << group_cnt << endl;
	
	return 0;
}


// 
#include <vector>

typedef pair<int, int> Point;
vector<vector<Point>> maps;

Point find(Point p) {
	Point parent = maps[p.first][p.second];

	if (parent == p) return p;
	return maps[p.first][p.second] = find(parent);
}

// merge and return the size
void merge(Point point_a, Point point_b) {
	Point root_a = find(point_a);
	Point root_b = find(point_b);

	if (root_a != root_b) {
		maps[root_b.first][root_b.second] = root_a;
	}
}

int main(void) {
	int N, M, // size of the map
		dr, dc,
		answer;

	char ch;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// init parent
	maps.resize(N, vector<Point>(M));
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			maps[r][c] = Point(r, c);
		}
	}

	// get data and update parent
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			// get data
			cin >> ch;

			int nr = r;
			int nc = c;
			// set dr and dc
			switch (ch) {
				case 'U': nr--; break;
				case 'D': nr++; break;
				case 'L': nc--; break;
				case 'R': nc++; break;
			}

			// merge
			Point A = {r, c};
			Point B = {nr, nc};
			merge(A, B);
		}
	}

	answer = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (maps[r][c] == Point(r, c)){
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> get_rot_map(int r, int c, int s, vector<vector<int>> m) {
	vector<vector<int>> new_m=m;
	r--; c--;
	while (s) {
		//cout << r + s << r - s << c + s << c - s;
		for (int i = r + s; i > r - s; i--) { //west
			new_m[i - 1][c - s] = m[i][c - s];
		}
		for (int i = r - s; i < r + s; i++){ //east
			new_m[i + 1][c + s] = m[i][c + s];
		}
		for (int i = c + s; i > c - s; i--){ //south
			new_m[r + s][i - 1] = m[r + s][i];
		}
		for (int i = c - s; i < c + s; i++) { //north
			new_m[r - s][i + 1] = m[r - s][i];
		}
		s--;
	}

	return new_m;
	
}

int get_min_row(vector<vector<int>> m) {
	int sum;
	int min = 5000;
	for (auto i : m) {
		sum = 0;
		for (int j : i) {
			sum += j;
		}
		if (sum < min) min = sum;
	}

	return min;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K;
	vector<vector<int>> m;
	vector<vector<int>> rot_m;
	vector<vector<int>> rotation;
	int res = 5000;
	int min;

	cin >> N >> M >> K;
	m.resize(N, vector<int>(M));
	rotation.resize(K, vector<int>(3));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> rotation[i][0] >> rotation[i][1] >> rotation[i][2];
	}
	 
	sort(rotation.begin(), rotation.end());

	do {

		rot_m = get_rot_map(rotation[0][0], rotation[0][1], rotation[0][2], m);

		for (int i = 1; i < K; i++) {
			rot_m = get_rot_map(rotation[i][0], rotation[i][1], rotation[i][2], rot_m);
		}

		min = get_min_row(rot_m);

		if (min < res) res = min;

	} while (next_permutation(rotation.begin(), rotation.end()));

	cout << res;
}
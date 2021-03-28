#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M, max_safe = 1;
	vector<vector<int>> space;

	cin >> N >> M;
	space.resize(N, vector<int>(M,0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			if (!input) continue;
			space[i][j] = 1;
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (space[row][col]) continue;
			//cout << row << col << endl;
			int safe = 1;
			int is_break = 0;
			while (true)
			{
				for (int i = row - safe; i <= row + safe; i++) {
					if (i < 0 || i >= N) continue;
					for (int j = col - safe; j <= col + safe; j++) {
						if (j < 0 || j >= M) continue;
						//cout << "check" << i << j << endl;
						if (space[i][j]) {
							is_break = 1;
							break;
						}
					}
					if (is_break) break;
				}
				if (is_break) break;
				safe++;
			}
		if (safe > max_safe) max_safe = safe;
		}
	}
	
	cout << max_safe;
}
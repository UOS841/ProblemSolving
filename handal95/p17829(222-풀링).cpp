#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<vector<int>> vec(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N;j++) {
			cin >> vec[i][j];
		}
	}
	
	while (N > 1) {
		N = N / 2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N;j++) {
				int box[4] = {
					vec[2 * i][2 * j], vec[2 * i][2 * j + 1],
					vec[2 * i + 1][2 * j], vec[2 * i + 1][2 * j + 1]
				};
				sort(box, box + 4);
				vec[i][j] = box[2];
			}
		}
	}
	cout << vec[0][0];
}
#include<iostream>
#include<vector>
#include<queue>

#define Cheese 1
#define Air 2
#define WithAir 3

using namespace std;

vector<vector<int>> set_Air(vector<vector<int>> m, pair<int,int> start) {
	queue<pair<int, int>> q;

	q.push(start);
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		m[now.first][now.second] = Air;

		if (now.first != 0 && m[now.first - 1][now.second] == 0) q.push({ now.first - 1, now.second });
		if (now.first != m.size() - 1 && m[now.first + 1][now.second] == 0) q.push({ now.first + 1, now.second });
		if (now.second != 0 && m[now.first][now.second - 1] == 0) q.push({ now.first, now.second - 1 });
		if (now.second != m[0].size() - 1 && m[now.first][now.second + 1] == 0) q.push({ now.first, now.second + 1 });

	}

	return m;
}

int main() {
	int N, M;
	vector<vector<int>> m;
	int time = 0;
	cin >> N >> M;

	m.resize(N, vector<int>(M));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	
	m = set_Air(m, { 0,0 });

	while (1) {
		
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << m[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;

//	start
		int num_of_cheese = 0;

		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (m[i][j] == Cheese) {
					num_of_cheese++;
					int cnt = 0;
					if (m[i - 1][j] == Air) cnt++;
					if (m[i + 1][j] == Air) cnt++;
					if (m[i][j - 1] == Air) cnt++;
					if (m[i][j + 1] == Air) cnt++;

					if (cnt >= 2) m[i][j] = WithAir;
				}

			}
		}
		//공기에 닿는 치즈 한번에 녹이기
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (m[i][j] == WithAir) m[i][j] = Air;
			}
		}

		//빈공간 update
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (m[i][j] == 0 && (m[i - 1][j] == Air || m[i + 1][j] == Air || m[i][j - 1] == Air || m[i][j + 1] == Air))
					m = set_Air(m, { i,j });
			}
		}

		if (!num_of_cheese) break;
		time++;
	}

	cout << time;
}
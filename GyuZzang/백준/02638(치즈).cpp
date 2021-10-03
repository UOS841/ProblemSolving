#include<iostream>
#include<vector>
#include<queue>

#define Cheese 1
#define Air 2
#define WithAir 3
#define Else 0

using namespace std;
vector<vector<int>> m;
queue<pair<int, int>> q;

void set_Air(pair<int,int> start) {

	q.push(start);
	m[start.first][start.second] = Air;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (now.first != 0 && m[now.first - 1][now.second] == 0) {
			m[now.first - 1][now.second] = Air;
			q.push({ now.first - 1, now.second });
		}
		if (now.first != m.size() - 1 && m[now.first + 1][now.second] == 0) {
			m[now.first + 1][now.second] = Air;
			q.push({ now.first + 1, now.second });
		}
		if (now.second != 0 && m[now.first][now.second - 1] == 0) {
			m[now.first][now.second - 1] = Air;
			q.push({ now.first, now.second - 1 });
		}
		if (now.second != m[0].size() - 1 && m[now.first][now.second + 1] == 0) {
			m[now.first][now.second + 1] = Air;
			q.push({ now.first, now.second + 1 });
		}
	}
}

int main() {
	int N, M;
	int time = 0;
	cin >> N >> M;

	m.resize(N, vector<int>(M));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	
	set_Air({ 0,0 });

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
					set_Air({ i,j });
			}
		}

		if (!num_of_cheese) break;
		time++;
	}

	cout << time;
}
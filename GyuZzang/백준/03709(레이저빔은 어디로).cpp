#include<iostream>
#include<vector>

using namespace std;

#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1

int main() {
	int TestCase;
	cin >> TestCase;

	while (TestCase--) {
		int n, r;
		vector<vector<int>> board;
		bool visited[52][52][4] = { 0 };
		pair<int, int> starting_point;
		pair<int, int> now_point;
		int dr[4] = {-1, 0, 1, 0};
		int dc[4] = {0, 1, 0, -1}; // u, r, d, l
		int laser_direction;

		cin >> n >> r;
		board.resize(n + 2, vector<int>(n + 2, 0));

		while (r--) {
			int mirror_row, mirror_col;
			cin >> mirror_row >> mirror_col;

			board[mirror_row][mirror_col] = 1;
		}

		cin >> starting_point.first >> starting_point.second;

		if (starting_point.first == 0)
			laser_direction = DOWN;
		else if (starting_point.second == 0)
			laser_direction = RIGHT;
		else if (starting_point.first == n + 1)
			laser_direction = UP;
		else laser_direction = LEFT;

		while (1) {
			// 다음 칸이 (index[1~n] && board[index]==0) 만족 --> direction 방향으로 한 칸 이동
			now_point.first = starting_point.first + dr[laser_direction];
			now_point.second = starting_point.second + dc[laser_direction];

			if (now_point.first*now_point.second && now_point.first <= n && now_point.second <= n){ //index[1~n]?
				starting_point = now_point;

				if (board[now_point.first][now_point.second]) { //mirror --> direction update
					if (visited[now_point.first][now_point.second][laser_direction]) {
						cout << "0 0";
						break;
					}
					visited[now_point.first][now_point.second][laser_direction] == 1;
					laser_direction = (laser_direction + 1) % 4;
				}
			}
			else {
				cout << now_point.first << " " << now_point.second<<endl;
				break;
			}
		}//to do ? 반복을 어떻게 잡지
	}
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int n, m;
	vector<vector<int>> grim;
	vector<vector<bool>> visited;
	queue<pair<int, int>> q;
	int width = 0, max_width = 0, cnt_grim = 0;
	
	cin >> n >> m;
	grim.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grim[i][j];
		}
	}	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			if (!grim[i][j]) continue;

			//grim is exist
			cnt_grim++;
			q.push({ i,j });
			visited[i][j] = 1;

			//check width of the grim
			width = 0;
			while (!q.empty()) {
				int row = q.front().first;
				int col = q.front().second;
				//cout << row << " " << col << endl;
				q.pop();
				width++;

				//check 4 side
				if (row < n-1 && !visited[row + 1][col]) {
					visited[row + 1][col] = 1;
					if(grim[row + 1][col]) q.push({ row + 1, col });
				}
				if (row > 0 && !visited[row - 1][col]) {
					visited[row - 1][col] = 1;
					if(grim[row - 1][col]) q.push({ row - 1, col });
				}				
				if (col < m-1 && !visited[row][col + 1]) {
					visited[row][col + 1] = 1;
					if(grim[row][col + 1]) q.push({ row, col + 1 });
				}
				if (col > 0 && !visited[row][col - 1]) {
					visited[row][col - 1] = 1;
					if(grim[row][col - 1]) q.push({ row, col - 1 });
				}
			}
			//update max_width
			if (max_width < width) max_width = width;
		}
	}
	cout << cnt_grim << endl << max_width;

}
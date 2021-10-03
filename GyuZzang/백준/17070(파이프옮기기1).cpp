#include<iostream>
#include<vector>

using namespace std;

int N;
vector<vector<int>> house;
int res=0;

void dfs(int i, int j, int state) {
	if (i == N - 1 && i == j) {
		res++;
	}

	if (i < N - 1 && j < N - 1 && !house[i][j + 1] && !house[i + 1][j] && !house[i + 1][j + 1]) dfs(i + 1, j + 1, 2);

	switch (state)
	{
		case 0:
		case 2:
			if (j < N - 1 && !house[i][j + 1]) {
				dfs(i, j + 1, 0);
			}
			if(state==0)break;
		case 1:
			if (i < N - 1 && !house[i + 1][j]) dfs(i + 1, j, 1);
			break; 
	}

}

int main() {
	int i, j;
	int state = 0; //0 가로, 1 세로, 2 대각선

	cin >> N;
	house.resize(N, vector<int>(N));

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}
	
	dfs(0, 1, 0);

	cout << res;
}

//
//struct status {
//	int cnt = 0;
//	int stat[2] = { 0, }; //status (1,0):가로 (1,1):대각선 (0,1):세로
//};
//
//int main() {
//
//	//init
//	int N, i, j;
//	cin >> N;
//	vector<vector<status>> dp;
//	vector<vector<int>> house;
//
//	dp.resize(N, vector<status>(N));
//	house.resize(N, vector<int>(N));
//
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			cin >> house[i][j];
//		}
//	}
//
//	//dp start
//	dp[0][1].cnt = 1;
//	dp[0][1].stat[0] = 1;
//	for (i = 0; i < N-1; i++) {
//		for (j = 0; j < N; j++) {
//			//벽면이거나 더할 값이 없는 경우
//			if (house[i][j] == 1 || dp[i][j].cnt == 0) continue;
//
//			//stat가
//			// 1. 가로(stat[0]==1)인 경우
//			if (dp[i][j].stat[0] == 1 && j < N - 2 && !house[i][j + 1] ) {
//				//오른쪽 cnt ++ & stat setting
//				dp[i][j + 1].cnt +=dp[i][j].cnt;
//				dp[i][j + 1].stat[0] = 1;
//
//			}
//			// 2. 세로(stat[1]==1)인 경우
//			if (dp[i][j].stat[1] == 1 && ((i < N - 2) || (j == N - 1)) &&!house[i + 1][j]) {
//				dp[i + 1][j].cnt += dp[i][j].cnt;
//				dp[i + 1][j].stat[1] = 1;
//			}
//
//			//대각선도 추가
//			if (i != N - 1 && j != N - 1 && !house[i + 1][j + 1] && !house[i][j + 1] && !house[i + 1][j]){
//				dp[i + 1][j + 1].cnt += dp[i][j].cnt;
//				dp[i + 1][j + 1].stat[0] = 1;
//				dp[i + 1][j + 1].stat[1] = 1;
//			}
//
//		}
//	}
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			cout << dp[i][j].cnt << " ";
//		}
//		cout << endl;
//	}
//
//	cout << dp[N - 1][N - 1].cnt;
//
//}
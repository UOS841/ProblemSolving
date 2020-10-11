//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int main() {
//	int N, K;
//	int dp[201][201] = { 0 };
//	cin >> N >> K;
//
//	if (K == 2) { cout << N + 1; return 0; }
//	if (K == 1) { cout << 1; return 0; }
//
//	//init
//	for (int i = 1; i <= K; i++) {
//		dp[1][i] = i;
//	}
//	for (int i = 1; i <= N; i++) {
//		dp[i][1] = 1;
//	}
//
//	for (int i = 1; i < N; i++) {
//		for (int j = 1; j < K; j++) {
//			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
//			if (dp[i + 1][j + 1] > 1000000000) dp[i + 1][j + 1] %= 1000000000;
//		}
//	}
//
//	//for (int i = 1; i <= N; i++) {
//	//	for (int j = 1; j <= K; j++) {
//	//		cout << dp[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	cout << dp[N][K];
//}
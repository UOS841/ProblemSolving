#include<iostream>
#include<vector>

using namespace std;

int dp[101][101][2] = { 0 };

int calc_dp(int w, int h, int d) {  // north:0, east:1
	int ret = 0;

	if (dp[w][h][d] > 0) {
		return dp[w][h][d];
	}

	if (d == 1) {
		if (w > 1) ret += calc_dp(w - 1, h, 1);
		if (h > 2) ret += calc_dp(w, h - 2, 0);
	} 
	else if (d == 0){
		if (h > 1) ret += calc_dp(w, h - 1, 0);
		if (w > 2) ret += calc_dp(w - 2, h, 1);
	}

	dp[w][h][d] = ret % 100000;

	return dp[w][h][d];
}

int main() {
	int w, h;
	cin >> w >> h;

	for (int i = 1; i < 101; i++) {
		dp[i][1][0] = dp[i][1][1] = dp[1][i][0] = dp[1][i][1] = 1;
	}
	cout << (calc_dp(w-1, h, 1) + calc_dp(w, h-1, 0)) % 100000;
}
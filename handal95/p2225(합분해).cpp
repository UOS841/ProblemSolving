#include<iostream>
#include <vector>

#define MOD 1000000000

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> dp(N + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int i = 1; i <= N; i++) {
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}
	}
	cout << dp[N];
}
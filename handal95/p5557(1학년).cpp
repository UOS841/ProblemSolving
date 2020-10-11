#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<long long>> dp(2, vector<long long>(21, 0));

	int cur = 0;
	int val;
	cin >> val;
	dp[cur][val] = 1;
	while (--N > 1) {
		cin >> val;
		for (int i = 0; i <= 20; i++) {
			if (i - val >=  0) dp[1 - cur][i - val] += dp[cur][i];
			if (i + val <= 20) dp[1 - cur][i + val] += dp[cur][i];
			dp[cur][i] = 0;
		}
		cur = 1 - cur;
	}
	cin >> val;
	cout << dp[cur][val];
}
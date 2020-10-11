#include <iostream>
#include <vector>


using namespace std;


int main() {
	int N;
	cin >> N;
	vector<vector<unsigned long long>> dp;
	dp.assign(2, vector<unsigned long long>(21, 0));

	int cur = 0;
	int next = 1;
	int val;
	cin >> val;
	dp[cur][val] = 1;
	N--;
	while (N-- > 1) {
		cin >> val;
		for (int i = 0; i <= 20; i++) {
			if (i - val >= 0){
				dp[next][i - val] += dp[cur][i];
			}
			if (i + val <= 20) {
				dp[next][i + val] += dp[cur][i];
			}
			dp[cur][i] = 0;
		}
		cur = 1 - cur;
		next = 1 - next;
	}
	cin >> val;
	cout << dp[cur][val];
}
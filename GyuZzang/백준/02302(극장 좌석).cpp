#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

void calcDp(int maxIdx) {
	for (int i = dp.size(); i <= maxIdx; i++) {
		dp.push_back(dp[i - 1] + dp[i - 2]);
	}
}

int main() {
	int N, M,
		prevFix = 0, nextFix,
		res = 1;

	cin >> N >> M;
	dp.push_back(1);
	dp.push_back(1);
	M++;

	while(M--){
		if(M) cin >> nextFix;
		else nextFix = N + 1;

		if (dp.size() <= nextFix - prevFix - 1)
			calcDp(nextFix - prevFix - 1);
		
		res *= dp[nextFix - prevFix - 1];
		prevFix = nextFix;
	}

	cout << res;
}

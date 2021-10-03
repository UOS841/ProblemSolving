#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct cost {
	int red;
	int green;
	int blue;
};

int main() {
	int N; // # of house
	vector<cost> dp_total_cost;

	cin >> N;
	dp_total_cost.resize(N);

	for (int i = 0; i < N; i++) {
		cost input;
		cin >> input.red >> input.green >> input.blue;
		dp_total_cost[i] = input;
	}

	for (int i = 1; i < N; i++) {
		dp_total_cost[i].red += min(dp_total_cost[i - 1].blue, dp_total_cost[i - 1].green);
		dp_total_cost[i].green += min(dp_total_cost[i - 1].blue, dp_total_cost[i - 1].red);
		dp_total_cost[i].blue += min(dp_total_cost[i - 1].red, dp_total_cost[i - 1].green);
	}

	cost res = dp_total_cost[N - 1];
	cout << min(res.red, min(res.green, res.blue));
}
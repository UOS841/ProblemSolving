#include <iostream>
#include <vector>
#include <cmath>
 
#define MAX_SIZE 15
using namespace std;
 
int dp[1 << MAX_SIZE][MAX_SIZE][10]; //bitmask, artist, cost
vector<vector<int>> cost;
 
int exchange(int bitmask, int artist, int current_cost, int buyers) {
    int N = cost.size();

    int ret = dp[bitmask][artist][current_cost];
    if (ret != 0){
        return ret;
    }
    ret = buyers;
 
    for (int i = 0; i < N; i++) {
        if (bitmask & (1 << i) || cost[artist][i] < current_cost) continue;
        int next_ret = exchange(bitmask | (1 << i), i, cost[artist][i], buyers + 1);
        ret = max(ret, next_ret);
    }
    return ret;
}
 
int main() {
    int N;
    cin >> N;
    cost.resize(N, vector<int>(N));
 
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            cost[i][j] = (row[j] - '0');
        }
    }

    int init_cost = 0;
    int buyer_count = 1;
    int answer = exchange(1, 0, init_cost, buyer_count);
    cout << answer;
}

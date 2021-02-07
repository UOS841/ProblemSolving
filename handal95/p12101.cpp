#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N;
    long K;
    cin >> N >> K;

    vector<vector<int>> dp(N+4, vector<int>(3, 0));
    dp[1][0] = dp[2][0] = dp[2][1] = 1;
    dp[3][1] = dp[3][2] = 1;
    dp[3][0] = 2;
    for(int i = 4; i <= N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-2][0] + dp[i-2][1] + dp[i-2][2];
        dp[i][2] = dp[i-3][0] + dp[i-3][1] + dp[i-3][2];
    }

    int sum = dp[N][0] + dp[N][1] + dp[N][2];
    if ((N == 1 && K == 1) || ( N == 2 && K == 2) || ( N == 3 && K == 4)){
        cout << N;
        return 0;
    } else if ( K > sum) {
        cout << "-1";
        return 0;
    }

    int cur = N;
    vector<int> answer;
    while(K >= 1 && cur >= 1){
        if( K <= dp[cur][0] ){
            answer.push_back(1);
            cur -= 1;
        } else if ( K <= dp[cur][0] + dp[cur][1]){
            answer.push_back(2);
            K -= (dp[cur][0]);
            cur -= 2;
        } else if ( K <= dp[cur][0] + dp[cur][1] + dp[cur][2]){
            answer.push_back(3);
            K -= (dp[cur][1] + dp[cur][0]);
            cur -= 3;
        }
    }

    cout << answer[0];
    for(int i = 1; i < answer.size(); i++){
        cout<< "+" << answer[i];
    }

    return 0;
}
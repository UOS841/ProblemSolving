#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> price_map;
price_map prices;

int answer = 1;
void dfs(int depth, int index, int current_price, string bitmask){
    int N = bitmask.length();

    if(depth > answer){
        answer = max(answer, depth);
    }
    for(int i = 0; i < N; i++){
        if(bitmask.at(i) == '0' && current_price <= prices[index][i]){
            bitmask.at(i) = '1';
            dfs(depth + 1, i, prices[index][i], bitmask);
            bitmask.at(i) = '0';
        }
    }
} 

int main(){
    int N;
    cin >> N;
    prices.resize(N, vector<int>(N));

    string bitmask;
    bitmask.assign(N, '0');
    for(int i = 0; i < N; i++){
        string row;
        cin >> row;
        for(int j = 0; j < N; j++){
            prices[i][j] = row[j] - '0';
        }
    }

    bitmask.at(0) = '1';
    dfs(1, 0, 0, bitmask);
    cout << answer << endl;
}
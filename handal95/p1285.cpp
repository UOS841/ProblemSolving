#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<char>> Coins;
void printCoins(Coins coins);

int answer = 400;
void dfs(Coins coins, int index){
    if(index == coins.size()){
        int tail_total = 0;
        for(int c = 0; c < coins.size(); c++){
            int tails = 0;
            for(int r = 0; r < coins.size(); r++){
                if(coins[r][c] == 'T'){
                    tails++;
                }
            }

            if(tails > coins.size()/2 ){
                for(int r = 0; r < coins.size(); r++){
                    coins[r][c] = (coins[r][c] == 'H' ? 'T' : 'H');
                }
                tails = coins.size() - tails;
            }
            tail_total += tails;
        }
        answer = min(answer, tail_total);
        return;
    }

    dfs(coins, index+1);
    for(int i = 0; i < coins.size(); i++){
        coins[index][i] = (coins[index][i] == 'H' ? 'T' : 'H');
    }

    dfs(coins, index+1);
    for(int i = 0; i < coins.size(); i++){
        coins[index][i] = (coins[index][i] == 'H' ? 'T' : 'H');
    }
}

int main(){
    int N;
    cin >> N;
    Coins coins(N, vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> coins[i][j];
        }
    }
    dfs(coins, 0);
    cout << answer << endl;
}

void printCoins(Coins coins){
    int N = coins.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << coins[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
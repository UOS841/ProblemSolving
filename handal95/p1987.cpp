#include <iostream>
#include <vector>

using namespace std;

int dR[4] = { 0, -1, 0, 1};
int dC[4] = { 1, 0, -1, 0};
typedef vector<vector<char>> Map;

Map map;
int answer = 0;
void dfs(int depth, vector<bool> path, int r, int c){
    answer = max(answer, depth);

    for(int d = 0; d < 4; d++){
        int nR = r + dR[d];
        int nC = c + dC[d];
        if(nR < 0 || nR >= map.size() || nC < 0 || nC >= map[0].size()){
            continue;
        }
        int tile = map[nR][nC] - 'A';
        if(path[tile] == false){
            path[tile] = true;
            dfs(depth+1, path, nR, nC);
            path[tile] = false;
        }
    }
}

int main(){
    int R, C;
    cin >> R >> C;
    map.resize(R, vector<char>(C));
    for(int r = 0; r < R; r++){
        string str;
        cin >> str;
        for(int c = 0; c < C; c++){
            map[r][c] = str[c];
        }
    }

    vector<bool> path(26, false);
    path[map[0][0] - 'A'] = true;
    dfs(1, path, 0, 0);
    cout << answer;
}
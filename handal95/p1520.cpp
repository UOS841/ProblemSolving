#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> Coord;
typedef vector<vector<int>> Map;

int main(){
    int N, M;
    cin >> N >> M;

    Map map(N, vector<int>(M));
    Map routes(N, vector<int>(M, 0));
    Map visited(N, vector<int>(M, false));

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> map[r][c];
        }
    }

    int dR[4] = { 0, 1, 0, -1};
    int dC[4] = { 1, 0, -1, 0};
    priority_queue<pair<int, Coord>> q;

    routes[0][0] = 1;
    q.push({map[0][0], {0, 0}});
    while(!q.empty()){
        pair<int, Coord> cur = q.top(); q.pop();
        int cur_value = cur.first;
        Coord cur_coord = cur.second;
        int r = cur_coord.first;
        int c = cur_coord.second;
        if(visited[r][c]){
            continue;
        }

        visited[r][c] = true;

        for(int d = 0; d < 4; d++){
            int nR = dR[d] + cur_coord.first;
            int nC = dC[d] + cur_coord.second;
            if(0 <= nR && nR < N && 0 <= nC && nC < M){
                if(map[nR][nC] < map[r][c]){
                    routes[nR][nC] += routes[r][c];
                    q.push({map[nR][nC], {nR, nC}});
                }
            }
        }
    }

    cout << routes[N-1][M-1] << endl;
}
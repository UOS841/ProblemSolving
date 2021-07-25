#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dR[8] = { 1, 1,  1, 0,  0, -1, -1, -1};
int dC[8] = { 1, 0, -1, 1, -1,  1,  0, -1};

struct Coord{
    int r;
    int c;
};

struct Mountain{
    int height;
    bool visited = false;
};

typedef vector<vector<Mountain>> Map;

void dfs(Map map, Coord coord){
    int r = coord.r;
    int c = coord.c;

    for(int d = 0; d < 8; d++){
        int nr = r + dR[d];
        int nc = c + dC[d];
        if(map[r][c] >= map[nr][nc]){

        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    Map map(N, vector<Mountain>(M));

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> map[r][c].height;
        }
    }

    int answer = 0;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(!map[r][c].visited){
                answer++;
                dfs(map, {r, c});
            }
        }
    }

    cout << answer;
}
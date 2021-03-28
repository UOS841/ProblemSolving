#include <iostream>
#include <vector>
#include <queue>


using namespace std;
enum Field{
    EMPTY = 0,
    SHARK = 1
};
struct Location{
    Field value;
    int distance;
};
struct Cell{
    int r;
    int c;
};

int dR[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dC[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<Location>> map(N, vector<Location>(M));

    queue<pair<Cell, int>> q;
    for (int r = 0; r < N; r++){
        for (int c = 0; c < M; c++){
            int value;
            cin >> value;
            map[r][c] = {(Field)value, N * M};
            if(value == SHARK){
                map[r][c].distance = 0;
                q.push({{r, c}, 0});  
            }
        }
    }

    while(!q.empty()){
        Cell cur = q.front().first;
        int distance = q.front().second;
        q.pop();

        for(int d = 0; d < 8; d++){
            int nr = cur.r + dR[d];
            int nc = cur.c + dC[d];
            if(0 <= nr && nr < N && 0 <= nc && nc < M){
                if(distance + 1 < map[nr][nc].distance){
                    map[nr][nc].distance = distance + 1;
                    q.push({{nr, nc}, distance + 1});
                }
            }
        }
    }

    int answer = 0;
    for (int r = 0; r < N; r++){
        for (int c = 0; c < M; c++){
            answer = max(answer, map[r][c].distance);
        }
    }
    cout << answer << endl;
}
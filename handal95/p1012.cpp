#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> map;
enum status {
    UNPLANT = 1,
    PLANT = 2,
};

int dr[4] = { 0, 1, 0, -1};
int dc[4] = { 1, 0, -1, 0};

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int M, N, K;
        cin >> M >> N >> K;
        map fields(N, vector<int>(M, UNPLANT));

        queue<pair<int, int>> q;
        for(int k = 0; k < K ; k++){
            int x, y;
            cin >> x >> y;
            fields[y][x] = PLANT;
            q.push({y, x});
        }

        int answer = K;
        while(!q.empty()){
            pair<int, int> coord = q.front(); q.pop();
            int r = coord.first;
            int c = coord.second;
            if(fields[r][c] == PLANT){
                fields[r][c] = UNPLANT;
                for(int d = 0; d < 4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(0 <= nr && nr < N && 0 <= nc && nc < M){
                        if(fields[nr][nc] == PLANT){
                            cout << "[" << nc << " " << nr << "]\n";
                            answer--;
                            q.({nr, nc});
                        }
                    }
                }
            }
        }

        cout << answer << "\n";
        fields.clear();
    }
}
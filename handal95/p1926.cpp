#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<int>> Map;

int main(){
    int N, // The size of rows
        M; // The size of cols

    cin >> N >> M;
    Map map(N, vector<int>(M));
    stack<pair<pair<int, int>, bool>> s;    // {row, col}

    // Input Data
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> map[r][c];
            if(map[r][c] == 1){
                s.push({{r, c}, false});
            }
        }
    }

    // BFS
    int map_size = 0;
    int answer_num = 0;
    int answer_size = 0;
    int dR[4] = { 0, 1, 0, -1 };
    int dC[4] = { 1, 0, -1, 0 };
    while(!s.empty()){
        int r = s.top().first.first;
        int c = s.top().first.second;
        int connected = s.top().second; 
        s.pop();

        if(map[r][c] == 0){
            continue;
        }
        if(!connected){
            answer_num++;
            answer_size = max(map_size, answer_size);
            map_size = 0;
        }

        map_size++;
        map[r][c] = 0;
        for(int d = 0; d < 4; d++){
            int nR = r + dR[d];
            int nC = c + dC[d];

            if(0 <= nR && nR < N && 0 <= nC && nC < M){
                if(map[nR][nC] == 1){
                    s.push({{nR, nC}, true});
                }
            }
        }
    }
    cout << answer_num << endl << max(map_size, answer_size);

    return 0;
}
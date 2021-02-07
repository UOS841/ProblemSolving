#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> Map;

Map copy_map(Map map);

int dR[4] = { 0, 1, 0, -1};
int dC[4] = { 1, 0, -1, 0};

Map next_flood(Map map){
    int N = map.size();
    int M = map[0].size();
    Map copied = copy_map(map);

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            if(map[r][c] != '*'){
                continue;
            }

            for(int d = 0; d < 4; d++){
                int nR = r + dR[d];
                int nC = c + dC[d];

                if(0 <= nR && nR < N && 0 <= nC && nC < M){
                    if(map[nR][nC] == '.'){
                        copied[nR][nC] = '*';
                    }
                }
            }
        }
    } 
    return copied;
}

Map copy_map(Map map){
    int N = map.size();
    int M = map[0].size();
    Map copied(N, vector<char>(M));
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            copied[r][c] = map[r][c];
        }
    }
    return copied;
}

void print_map(Map map){
    int N = map.size();
    int M = map[0].size();
    
    cout << endl;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cout << map[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int N,  // The size of rows
        M;  // The size of cols
    cin >> N >> M;
    Map map(N, vector<int>(M));
    Map water_map(N, vector<int>(M));

    pair<int, int> start;
    pair<int, int> end;

    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> map[r][c];

            if(map[r][c] == 'S'){
                start = {r, c};
            } else if(map[r][c] == 'D'){
                end = {r, c};
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});

    while(!q.empty()){
        pair<int, int> cur = q.front().first;
        int count = q.front().second;
        q.pop();

        map = next_flood(map);
        for(int d = 0; d < 4; d++){
            int nR = cur.first + dR[4];
            int nC = cur.second + dC[4];

        }
        print_map(map);
    }
}
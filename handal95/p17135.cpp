#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> Map;
typedef vector<int> Archers;

bool is_win(Map map){
    int N = map.size();
    int M = map[0].size();
    for(int r = 0; r<N;r++){
        for(int c=0; c<M;c++){
            if(map[r][c] == 1){
                return false;
            }
        }
    }
    return true;
}

Map turn_enermy(Map map){
    int N = map.size();
    int M = map[0].size();
    for(int r = N-1 ; r > 0; r--){
        for(int c = 0; c < M; c++){
            map[r][c] = map[r-1][c];
        }
    }
    for(int c = 0 ; c < M; c++){
        map[0][c] = 0;
    }
    return map;
}

pair<Map, int> turn_archer(Map map, Archers archers, int D){
    int N = map.size();
    int M = map[0].size();
    int kill = 0;

    // Kill Algorithms
    for(int i = 0 ; i < 3; i++){
        // TARGET
        queue<pair<int, int>> targets;
        for(int d = 0; d <= D; d++){
            int nxt_r = N;
            int nxt_c = archers.at(i) - d;
            if ((0 <= nxt_r && nxt_r < N) &&
                (0 <= nxt_c && nxt_c < M) &&
                map[nxt_r][nxt_c] > 0){
                targets.push(make_pair(nxt_r, nxt_c));
            }

            for(int j = 0 ; j < d; j++){
                nxt_r = nxt_r - 1;
                nxt_c = nxt_c + 1;
                if ((0 <= nxt_r && nxt_r < N) &&
                    (0 <= nxt_c && nxt_c < M) &&
                    map[nxt_r][nxt_c] > 0){
                    targets.push(make_pair(nxt_r, nxt_c));
                }
            }

            for(int j = 0 ; j < d; j++){
                nxt_r = nxt_r + 1;
                nxt_c = nxt_c + 1;
                if ((0 <= nxt_r && nxt_r < N) &&
                    (0 <= nxt_c && nxt_c < M) &&
                    map[nxt_r][nxt_c] > 0){
                    targets.push(make_pair(nxt_r, nxt_c));
                }
            }
        }
        // SHOOT
        pair<int, int> target;
        while(!targets.empty()){
            target = targets.front(); targets.pop();
            if(map[target.first][target.second] == 1){
                map[target.first][target.second] = 2;
                break;
            }else if(map[target.first][target.second] > 0){
                break;
            }
        }
    }
    for(int r = 0; r < N ; r++){
        for(int c = 0 ; c < M; c++){
            if(map[r][c]==2){
                kill++;
                map[r][c] = 0;
            }
        }
    }

    return make_pair(map, kill);
}


int main(){
    int N, 
        M, 
        D;
    cin >> N >> M >> D;
    Map map(N, vector<int>(M));
    int exist;
    for(int r = 0 ; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> exist;
            map[r][c] = exist;
        }
    }

    Archers archer(3);
    queue<Archers> q;
    for(int i = 0 ; i < M-2; i++){
        archer.at(0) = i;
        for(int j = i+1 ; j < M-1 ; j++){
            archer.at(1) = j;
            for(int k = j+1; k < M; k++){
                archer.at(2) = k;
                q.push(archer);
            }
        }
    }

    int answer = 0;
    while(!q.empty()){
        Archers archer = q.front(); q.pop();
        Map copied(N, vector<int>(M));
        copied.assign(map.begin(), map.end());
        int kill = 0;
        bool win = false;
        bool defeat = false;
        pair<Map, int> result;
        
        while(true){
            result = turn_archer(copied, archer, D);
            copied = result.first;
            kill += result.second;
            win = is_win(copied);
            if(win == true){
                answer = (answer < kill) ? kill : answer;
                break;
            }
            copied = turn_enermy(copied);
        }
    }
    cout << answer << endl;
}
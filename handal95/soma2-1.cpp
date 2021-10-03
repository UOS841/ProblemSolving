#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {
    BLANK = 0,
    WALL = 1,
    BOX = 2,
    SOMA = 3,
    KEY =4 
};

typedef vector<vector<int>> Map;
typedef vector<vector<pair<bool, bool>>> Visit;
struct Soma{
    int r;
    int c;
};

int dR[4] = { 0, 1, 0, -1};
int dC[4] = { 1, 0, -1, 0};

bool check(int M, int N, int r, int c){
    return (0 <= r && r < M && 0 <= c && c < N);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T-- > 0){
        int M, N;
        cin >> M >> N;

        Soma soma;
        Soma soma_key;
        Map map(M, vector<int>(N));
        // first : key
        // second : box
        Visit isvisit(M, vector<pair<bool, bool>>(N, {false, false}));
        for(int r = 0; r < M; r++){
            for(int c = 0; c < N; c++){
                cin >> map[r][c];
                if(map[r][c] == SOMA){
                    soma.r = r;
                    soma.c = c;
                }
            }
        }

        // SOMA -> KEY
        queue<Soma> q_key;
        q_key.push(soma);
        bool find_key = false;
        while(!q_key.empty()){
            Soma cur = q_key.front();
            q_key.pop();

            if(isvisit[cur.r][cur.c].first){
                continue;
            }
            isvisit[cur.r][cur.c].first = true;

            if(map[cur.r][cur.c] == KEY){
                soma_key = {cur.r, cur.c};
                find_key = true;
                break;
            }

            for(int d = 0; d < 4; d++){
                int nr = cur.r + dR[d];
                int nc = cur.c + dC[d];
                if(check(M, N, nr, nc) && map[nr][nc] != WALL && !isvisit[nr][nc].first){
                    q_key.push(Soma{nr, nc});
                }
            }
        }

        // KEY -> BOX
        bool find_box = false;
        if(find_key){
            queue<Soma> q_box;
            q_box.push(soma_key);
            while(!q_box.empty()){
                Soma cur = q_box.front();
                q_box.pop();

                if(isvisit[cur.r][cur.c].second){
                    continue;
                }
                isvisit[cur.r][cur.c].second = true;

                if(map[cur.r][cur.c] == BOX){
                    find_box = true;
                    break;
                }

                for(int d = 0; d < 4; d++){
                    int nr = cur.r + dR[d];
                    int nc = cur.c + dC[d];
                    if(check(M, N, nr, nc) && map[nr][nc] != WALL && !isvisit[nr][nc].second){
                        q_box.push(Soma{nr, nc});
                    }
                }
            }
        }

        cout << (find_box ? "1\n" : "0\n");
    }
}
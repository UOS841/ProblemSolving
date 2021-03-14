#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<pair<int, vector<bool>>>> Map;
struct Monkey{
    int y;
    int x;
    int jump;
    int move = 0;
};

enum{
    FIELD = 0,
    BLOCK = 1
};

bool check(int H, int W, int y, int x){
    return (0 <= y && y < H && 0 <= x && x < W);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, W, H;
    cin >> K;
    cin >> W >> H;


    Map map(H, vector<pair<int, vector<bool>>>(W));
    for (int y = 0; y < H; y++){
        for (int x = 0; x < W; x++){
            cin >> map[y][x].first;
            map[y][x].second.assign(K + 1, false);
        }
    }

    queue<Monkey> q;
    q.push(Monkey{0, 0, 0});

    int dY[4] = {0, 1, 0, -1};
    int dX[4] = {1, 0, -1, 0};

    int jY[8] = {-2, -1,  1,  2,  2,  1, -1, -2};
    int jX[8] = { 1,  2,  2,  1, -1, -2, -2, -1};

    int answer = -1;
    while (!q.empty()){
        Monkey monkey = q.front();
        int y = monkey.y;
        int x = monkey.x;
        int j = monkey.jump;
        int m = monkey.move;
        q.pop();

        if(y == H -1 && x == W -1){
            answer = monkey.move;
            break;
        }
        if(map[y][x].second[j]){
            continue;
        }
        map[y][x].second[j] = true;

        // Move
        for(int d = 0; d < 4; d++){
            int ny = y + dY[d];
            int nx = x + dX[d];
            if (check(H, W, ny, nx) && map[ny][nx].first != BLOCK){
                q.push(Monkey{ny, nx, j, m + 1});
            }
        }

        if(j < K){
            for (int d = 0; d < 8; d++){
                int ny = y + jY[d];
                int nx = x + jX[d];
                if (check(H, W, ny, nx) && map[ny][nx].first != BLOCK){
                    q.push(Monkey{ny, nx, j + 1, m + 1});
                }
            }
        }
    }
    cout << answer;
}
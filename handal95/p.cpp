#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
 
using namespace std;
 
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
 
typedef pair<int, int> Cell;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(N, 0));
    vector<vector<int>> is_visited(N, vector<int>(N, false));
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
 
    int answer = 0;
    while (true){
        vector<vector<int>> outsides(N, vector<int>(N, 0));
        bool inner[102][102] = { true, };
        int chk[102][102] = { 0, };
 
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
 
            q.pop();
            if (is_visited[r][c])
                continue;
 
            is_visited[r][c] = true;
            inner[r][c] = false;
 
            for (int i = 0; i < 4; i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
 
                if (!((0 <= nr && nr < N) && (0 <= nc && nc < M)))
                    continue;
 
                if (map[nr][nc] == 1)
                    outsides[nr][nc]++;
 
                else if(!is_visited[nr][nc])
                    q.push(make_pair(nr, nc));
            }
        }
 
        bool erase = false;
        for(int i = 0 ; i < N; i ++)
            for (int j = 0; j < M; j++){
                if (outsides[i][j] >= 2){
                    map[i][j] = 0;
                    erase = true;
                }
            }
 
        if (erase){
            answer++;
        }
        else{
            cout << answer;
            return;
        }
    }
 
    cout << answer;
 
    return 0;
}
 
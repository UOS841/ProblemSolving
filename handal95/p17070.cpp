#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<int>> Map;
typedef pair<int, int> Pipe;

enum CELL {
    EMPTY = 0,
    BLOCK = 1,
};
enum DIR {
    GARO = -1,
    DIAG = 0,
    SERO = 1,
};


int main(){
    int N;
    cin >> N;
    Map map(N, vector<int>(N));

    // Init Map
    for(int r = 0 ; r < N ; r++){
        for(int c = 0 ; c < N ; c++){
            cin >> map[r][c];
        }
    }

    Pipe pipe = make_pair(0, 1);
    DIR direction = GARO;

    stack<pair<Pipe, DIR>> s;
    s.push(make_pair(pipe, direction));

    int answer = 0;
    while(!s.empty()){
        pair<Pipe, DIR> cur = s.top();
        Pipe cur_pipe = cur.first;
        DIR cur_dir = cur.second;
        s.pop();

        int row = cur_pipe.first;
        int col = cur_pipe.second;
        //Break Point
        if(row == map.size()-1 && col == map[0].size()-1){
            answer++;
            continue;
        }

        bool is_in_row = (row + 1 < map.size());
        bool is_in_col = (col + 1 < map[0].size());
        //DIAG
        if(is_in_col && is_in_row && (map[row+1][col+1] == EMPTY) &&
          (map[row+1][col] == EMPTY) && (map[row][col+1] == EMPTY)){
            Pipe next_pipe = make_pair(row+1, col+1);
            s.push(make_pair(next_pipe, DIAG));
        }
        //GARO
        if( is_in_col && cur_dir != SERO && map[row][col+1] == EMPTY){
            Pipe next_pipe = make_pair(row, col+1);
            s.push(make_pair(next_pipe, GARO));
        }
        
        //SERO
        if( is_in_row && cur_dir != GARO && map[row+1][col] == EMPTY){
            Pipe next_pipe = make_pair(row+1, col);
            s.push(make_pair(next_pipe, SERO));
        }
    }

    cout << answer;
}
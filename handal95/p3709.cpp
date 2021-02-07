#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<vector<int>>> Board;

enum Direction{
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE,
};

vector<pair<int, int>> mirrors;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int N, // The size of board
            R; // The number of mirror
        cin >> N >> R;

        Board board(N + 2, vector<vector<int>>(N + 2, vector<int>(5, 0)));
        for(int r = 0; r < R; r++){
            int row, col;
            cin >> row >> col;
            
            board[row][col][NONE] = 1;
        }
        int r, c;
        cin >> r >> c;

        int dR[4] = { -1, 0, 1, 0};
        int dC[4] = { 0, 1, 0, -1};

        int direction = NONE;
        if(r == 0)
            direction = DOWN;
        else if(r == N + 1)
            direction = UP;
        else if(c == 0)
            direction = RIGHT;
        else if(c == N + 1)
            direction = LEFT;

        while(true){
            r = r + dR[direction];
            c = c + dC[direction];

            if(r == 0 || r == N+1 || c == 0 || c == N+1){
                cout << r << " " << c << endl;
                break;
            }

            if(board[r][c][NONE] == 0){
                board[r][c][direction] = 1;
            } else if(board[r][c][NONE] == 1){
                if(board[r][c][direction] == 1){
                    cout << "0 0" << endl;
                    break;
                }
                board[r][c][direction] = 1;
                direction = (direction + 1) % 4;
            }
        }
    }
}
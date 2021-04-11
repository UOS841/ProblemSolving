#include <iostream>
#include <vector>

using namespace std;

enum Field {
    EMPTY = '.',
    MINERAL = 'x'
};

enum Field {
    CHANG = 0,
    SANG = 1
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int R, C;
    cin >> R >> C;
    vector<vector<int>> map(R, vector<int>(C));
    for(int r = 0; r < R; r++){
        string str;
        cin >> str;
        for(int c = 0; c < C; c++){
            map[r][c] = str[c];
            if(map[r][c] == EMPTY){
                // EMPTY
                map[r][c] = 5;
            } else {
                // MINERAL
                map[r][c] = 7;
            }
        }
    }

    int N;
    cin >> N;
    int turn = CHANG; 
    vector<int> sticks(N);
    for(int i = 0; i < N; i++){
        cin >> sticks[i];
    }

    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cout << map[r][c] << " ";
        }
        cout << endl;
    }
}
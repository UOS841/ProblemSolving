#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

char map[5][5];
set<vector<int>> s;

bool is_adjacent(bool is_visited[5][5], int r, int c){
    if(1 <= r && is_visited[r-1][c] == true)
        return true;
    if(r <= 3 && is_visited[r+1][c] == true)
        return true;
    if(1 <= c && is_visited[r][c-1] == true)
        return true;
    if(c <= 3 && is_visited[r][c+1] == true)
        return true;
    return false;
}

void dfs(bool is_visited[5][5], int d, string str){
    int answer = 0;
    if(d==7){
        int count = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.at(i)=='S')
                count++;
        }
        if(count>=4){
            vector<int> pick(7);
            for(int i = 0 ; i < 5; i++){
                for(int j = 0 ; j < 5; j++){
                    if(is_visited[i][j]){
                        pick.push_back(i*5+j);
                    }
                }
            }
            sort(pick.begin(), pick.end());
            s.insert(pick);
        }
        return;
    }

    for(int nr = 0; nr < 5; nr++){
        for(int nc = 0; nc< 5; nc++){
            if(is_visited[nr][nc] == false &&
               is_adjacent(is_visited, nr, nc) == true){
                is_visited[nr][nc] = true;
                str.at(d) = map[nr][nc];
                dfs(is_visited, d+1, str);
                is_visited[nr][nc] = false;
            }
        }
    }
}

int main(){
    bool is_visited[5][5];
    for(int i = 0 ; i < 5 ; i++){
        cin >> map[i];
        for(int j = 0 ; j < 5 ; j++){
            is_visited[i][j] = false;
        }
    }

    for(int r = 0; r < 5; r++){
        for(int c = 0; c < 5; c++){
            string str;
            str.resize(8);
            is_visited[r][c] = true;
            str.at(0) = map[r][c];
            dfs(is_visited, 1, str);
            is_visited[r][c] = false;
        }
    }

    cout << s.size() << endl;
}

/*
abcde
fghij
klmno
pqrst
uvwxy
*/
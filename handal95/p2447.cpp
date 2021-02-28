#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Map;
Map map;

void devide_and_conquer(int size, int r, int c){
    if(size == 1){
        map[r][c] = '*';
        return;
    }

    int nsize = size/3;
    for(int nr = 0; nr < 3; nr++){
        for(int nc = 0; nc < 3; nc++){
            if(nr == 1 && nc == 1){
                continue;
            }
            devide_and_conquer(nsize, r + nsize * nr, c + nsize * nc);
        }
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    map.resize(N, vector<char>(N, ' '));
    devide_and_conquer(N, 0, 0);

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cout << map[r][c];
        }
        cout << "\n";
    }
}
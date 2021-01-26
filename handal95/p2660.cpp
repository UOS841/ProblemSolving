#include <iostream>
#include <vector>
#include <cmath>


using namespace std;
typedef vector<vector<int>> Friendship;

int main(){
    int N;
    cin >> N;
    Friendship members(N+1, vector<int>(N+1, N));
    vector<int> friends(N+1, 0);
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }
        members[a][b] = members[b][a] = 1;
        members[a][a] = members[b][b] = 0;
    }


    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                members[i][j] = min(members[i][j], members[i][k] + members[k][j]);
            }
        }
    }

    int answer = N;
    vector<int> lists(0);
    for(int i = 1; i <= N; i++){
        int score = 0;
        for(int j = 1; j <= N; j++){
            score = max(score, members[i][j]);
        }
        if(score < answer){
            answer = score;
            lists = vector<int>();
        }
        if(score == answer){
            lists.push_back(i);
        }
    }

    cout << answer << " " << lists.size() << endl;
    for(int i = 0; i < lists.size(); i++){
        cout << lists[i] << " ";
    }
}
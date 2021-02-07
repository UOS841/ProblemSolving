#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<int>> Graph;
Graph peoples;

bool dfs(int depth, int cur, vector<bool> isVisited){
    bool ret = false;

    if(depth == 4){
        return true;
    }

    for(int i = 0; i < peoples[cur].size(); i++){
        int next = peoples[cur][i];
        if(!isVisited[next]){
            isVisited[next] = true;
            ret = dfs(depth + 1, next, isVisited);
            isVisited[next] = false;
        }
        if(ret) break;
    }
    return ret;
}

int main(){
    int N,  // The number of peoples
        M;  // The number of relationship
    cin >> N >> M;

    peoples.assign(N, vector<int>());
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        peoples[A].push_back(B);
        peoples[B].push_back(A);
    }

    bool answer = false;
    for(int i = 0; i < N; i++){
        vector<bool> isVisted(N, false);
        isVisted[i] = true;
        answer = dfs(0, i, isVisted);
        isVisted[i] = false;
        if(answer){
            cout << "1" << endl;
            return 0;
        }
    }
    cout << "0" << endl;
}
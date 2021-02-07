#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N,  // The number of students
        M,  // The number of questions
        X;  // The id of student
    cin >> N >> M >> X;
    vector<int> students(N+1);

    vector<vector<int>> graph_upper(N + 1, vector<int>());   // downside
    vector<vector<int>> graph_lower(N + 1, vector<int>());   // upside
    for(int q = 0; q < M; q++){
        int u, v;
        cin >> u >> v;

        graph_upper[v].push_back(u);    // u is higher than v
        graph_lower[u].push_back(v);    // v is lower than u
    }

    vector<bool> visited;
    queue<int> q;
    

    visited.assign(N+1, false);
    q.push(X);
    int upper = 0;

    // 상ㅎ

    while(!q.empty()){
        int cur = q.front(); q.pop();
        upper++;
        if(visited[cur]){
            continue;
        }
        visited[cur] = true;
        for(int j = 0; j < graph_upper[cur].size(); j++){
            int nxt = graph_upper[cur][j];
            if(!visited[nxt]){
                q.push(nxt);
            }
        }
    }

    visited.assign(N+1, false);
    q.push(X);
    int lower = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(visited[cur]){
            continue;
        }
        lower++;
        visited[cur] = true;
        for(int j = 0; j < graph_lower[cur].size(); j++){
            int nxt = graph_lower[cur][j];
            if(!visited[nxt]){
                q.push(nxt);
            }
        }
    }

    cout << upper << " " <<  (N - lower + 1);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef vector<vector<int>> Graph;
typedef vector<bool> Nodes;

int main(){
    int N,  // number of Nodes
        M,  // number of Edges
        V;  // number of Root Node
    cin >> N >> M >> V;

    Graph graph(N + 1, vector<int>());
    for(int m = 0; m < M; m++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS
    Nodes visited(N + 1, false);
    stack<int> s; s.push(V);

    while(!s.empty()){
        int cur = s.top();
        bool isMove = false;
        if(!visited[cur]){
            cout << cur << " ";
        }
        visited[cur] = true;

        for(int i = 0; i < graph[cur].size(); i++){
            int nxt = graph[cur][i];
            if(!visited[nxt]){
                s.push(nxt);
                isMove = true;
                break;
            }
        }
        if(!isMove){
            s.pop();
        }
    }
    cout << endl;

    // BFS
    visited.assign(N + 1, false);
    queue<int> q;
    q.push(V); visited[V] = true;
    cout << V << " ";

    while(!q.empty()){
        int cur = q.front(); q.pop();
    
        for(int i = 0; i < graph[cur].size(); i++){
            int nxt = graph[cur][i];
            if(!visited[nxt]){
                cout << nxt << " ";
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    cout << endl;
}
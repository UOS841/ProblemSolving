#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>());
    for(int edge = 0; edge < M; edge++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    vector<bool> is_visited(N + 1, false);
    for(int node = 1; node <= N; node++){
        if(!is_visited[node]){
            answer++;
            is_visited[node] = true;

            queue<int> q;
            q.push(node);
            while(!q.empty()){
                int cur = q.front(); q.pop();

                for(int i = 0; i < graph[cur].size(); i++){
                    int next = graph[cur][i];
                    if(!is_visited[next]){
                        is_visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    cout << answer << endl;
}
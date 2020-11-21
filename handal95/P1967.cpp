#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int index;
    vector<pair<int, int>> edges;
};

vector<Node> nodes;
int max_value = 0;
int root = 0;

void dfs(int v, int value, vector<bool> visited){
    if(value > max_value){
        max_value = value;
        root = v;
    }

    for(int i = 0 ; i < nodes[v].edges.size() ; i++){
        int node = nodes[v].edges[i].first;
        int weight = nodes[v].edges[i].second;
        if(!visited[node]){
            visited[node] = true;
            dfs(node, value + weight, visited);
            visited[node] = false;
        }
    }
}

void stack(int cnt){
    if (cnt % 100 == 0){
        cout << cnt << "th stack " << endl;
    }

    if(cnt > 1000000){
        return;
    }else{
        stack(cnt+1);
    }
}
int main(){
    stack(0);
    // int N;
    // cin >> N;
    // nodes.resize(N+1);
    // for(int i = 0; i <= N; i++){
    //     nodes[i].index = i;
    // }

    // for(int i = 1; i < N; i++){
    //     int A, B, w;
    //     cin >> A >> B >> w;
    //     nodes[A].edges.push_back(make_pair(B, w));
    //     nodes[B].edges.push_back(make_pair(A, w));
    // }

    // vector<bool> visited(N+1, false);

    // visited[0] = visited[1] = true;
    // dfs(1, 0, visited);
    // visited[1] = false;

    // visited[root] = true;
    // dfs(root, 0, visited);

    // cout << max_value;
}

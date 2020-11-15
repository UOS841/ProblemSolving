#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int index;
    vector<int> edges;
};

vector<int> depth;
vector<int> parents;
vector<Node> nodes;

void dfs(int n){
    Node cur = nodes[n];
    int size = cur.edges.size();
    for(int i = 0; i < size; i++){
        int next = cur.edges[i];

        if(parents[next] == 0){
            parents[next] = n;
            depth[next] = depth[n] + 1;
            dfs(next);
        }
    }
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    int N;
    cin >> N;
    nodes.resize(N+1);
    parents.resize(N+1);
    depth.resize(N+1);
    for(int i = 0; i <= N; i++){
        nodes[i].index = i;
    }

    int A, B;
    for(int i = 1; i < N; i++){
        cin >> A >> B;
        nodes[A].edges.push_back(B);
        nodes[B].edges.push_back(A);
    }

    parents[1] = 1;
    depth[1] = 1;
    dfs(1);

    int M;
    cin >> M;
    for(int i = 0; i < M ; i++){
        cin >> A >> B;

        while(depth[B] < depth[A]) A = parents[A];
        while(depth[A] < depth[B]) B = parents[B];
        while(A != B){
            A = parents[A];
            B = parents[B];
        }
        cout << A << "\n";
    }
}
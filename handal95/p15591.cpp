#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct USADO {
    int index;
    int value;
};
typedef vector<vector<USADO>> Graph;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,  // The number of videos (1 <= N <= 5,000)
        Q;  // The number of queries (1 <= Q <= 5,000)
    cin >> N >> Q; 

    Graph graph(N + 1, vector<USADO>());
    for(int i = 0; i < N - 1; i++){
        int p, q,  // The index of video
            r;     // The USADO between p and q
        cin >> p >> q >> r;
        graph[p].push_back(USADO{q, r});
        graph[q].push_back(USADO{p, r});
    }

    for(int i = 0; i < Q; i++){
        int k,  // USADO threshold
            v;  // The index of video
        cin >> k >> v;

        int answer = 0;
        queue<int> q; q.push(v);
        vector<bool> visited(N + 1, false);
        visited[v] = true;
        while(!q.empty()){
            int cur_index = q.front(); q.pop();

            for(int j = 0; j < graph[cur_index].size(); j++){
                USADO node = graph[cur_index][j];
                if(!visited[node.index]){
                    visited[node.index] = true;

                    int value = node.value;
                    if(value >= k){
                        answer++;
                        q.push(node.index);
                    }
                }
            }
        }
        cout << answer << "\n";
    }
} 

// Another approaches : Union-Find 

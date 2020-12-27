#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum GenderType{
    MALE = 0,
    FEMALE = 1
};

typedef vector<GenderType> University;
typedef vector<int> UniversityGroup;
typedef vector<vector<int>> Graph;
typedef pair<int, pair<int, int>> Edge;

UniversityGroup group;

int find(int x){
    if(group[x] == x)
        return x;
    return group[x] = find(group[x]);
}

void merge(int a, int b) {
	int root_a = find(a);
    int root_b = find(b);
    group[root_b] = root_a;
}

bool isUnion(int a, int b) {
    return (find(a) == find(b));
}

int main(){
    int N,  // The number of nodes
        M;  // The number of edges
    cin >> N >> M;

    // Group init
    group.resize(N + 1);
    for(int i = 1; i <= N; i++){
        group[i] = i;
    }

    // Node init. 
    char gender_type;
    University univ_gender(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> gender_type;
        univ_gender[i] = (gender_type == 'M' ? MALE : FEMALE);
    }

    // Edge init. with gender filter  
    int U, V, dist;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for(int i = 0; i < M; i++){
        cin >> U >> V >> dist;
        // connect with different gender type
        if(univ_gender[U] != univ_gender[V]){
            pq.push(Edge(dist, {U, V}));
        }
    }

    // MST : Kruskal
    int answer = 0;
    while(!pq.empty()){
        Edge edge = pq.top();
        int dist = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        pq.pop();

        if(!isUnion(u, v)){
            merge(u, v);
            answer += dist;
        }
    }

    // Output
    for(int i = 2; i <= N; i++){
        if(!isUnion(1, i)){
            cout << -1;
            return 0;
        }
    }

    cout << answer;
    return 0;
}
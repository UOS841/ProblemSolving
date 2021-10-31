#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];

struct Edge {
    int v1;
    int v2;
    int cost;
};

bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}

int find(int u){
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int merge(int u, int v, int cost){
	u = find(u);
	v = find(v);

	if (u == v) return 0;

	parent[u] = v;
	return cost;
}

int main() {
    int V, E,
        total_cost = 0;
    vector<Edge> edges;

    cin >> V >> E;
    edges.resize(E);

    for (int i = 0; i < V; i++) {
		parent[i] = i;
	}

    for (int i = 0; i < E; i++){
        Edge edge;
        cin >> edge.v1 >> edge.v2 >> edge.cost;
        edges[i] = edge;
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < E; i++){
        int v1 = edges[i].v1;
        int v2 = edges[i].v2;
        int cost = edges[i].cost;
        total_cost += merge(v1, v2, cost);
    }

    printf("%d\n",total_cost);
}
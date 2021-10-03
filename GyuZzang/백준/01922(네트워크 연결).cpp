#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int parent[1001];
bool check;

struct Edge {
	int start;
	int end;
	int cost;
};

struct compare {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

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
	int N, M,
		tot_cost = 0;
	priority_queue<Edge, vector<Edge>, compare> edges;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	while (M--) {
		int start, end, cost;
		cin >> start >> end >> cost;
		edges.push({ start,end,cost });
	}

	while (!edges.empty()) {
		Edge e = edges.top();
		edges.pop();
		tot_cost += merge(e.start, e.end, e.cost);
	}

	cout << tot_cost;
}
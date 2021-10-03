#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

vector<int> parent;

struct Edge {
	int dist;
	int node1;//index
	int node2;//index
};

struct compare {
	bool operator()(Edge e1, Edge e2) {
		return e1.dist > e2.dist;
	}
};

int find(int u){
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
		
	if (u != v) parent[u] = v;
}

int get_edge_dist(pair<int, int> x, pair<int, int> y) {
	return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

int main() {
	int N, C, ans = 0, cnt = 0 ;
	vector<pair<int,int>> points;
	priority_queue<Edge, vector<Edge>, compare > edges;

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> C;
	points.resize(N);
	parent.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> points[i].first >> points[i].second;
		parent[i] = i;
	}

	//make edges
	for (int i = 0; i < N - 1; i++) {
		for (int j = i; j < N; j++) {
			Edge edge = { get_edge_dist(points[i],points[j]), i, j };
			if (edge.dist >= C) edges.push(edge);
		}
	}

	//start merge
	int num_of_edges = edges.size();
	int i;
	for (i = 0; i < num_of_edges; i++) {
		Edge now = edges.top();
		edges.pop();
		if (find(now.node1) == find(now.node2)) continue;
		merge(now.node1, now.node2);
		ans += now.dist;
		cnt++;
		if (cnt == N - 1) break;
	}

	if (i == num_of_edges) ans = -1;

	cout << ans;
}
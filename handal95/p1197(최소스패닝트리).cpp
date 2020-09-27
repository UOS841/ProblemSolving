#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parents;
typedef pair<int, pair<int, int>> Edge;

int find(int x) {
	if (x == parents[x])
		return x;
	return parents[x] = find(parents[x]);
}

void merge(int a, int b) {
	int root_a = parents[a];
	int root_b = parents[b];
	if (root_a == root_b) 
		return;
	parents[root_b] = root_a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V,	// number of vertex
		E;	// number of edges
	cin >> V >> E;
	parents.resize(V+1);
	priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

	for (int i = 1; i <= V; i++) {
		parents.at(i) = i;
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push(make_pair(C, make_pair(A, B)));
	}

	long long answer = 0;
	while (!pq.empty()) {
		Edge edge = pq.top();
		int val = edge.first;
		int A  = edge.second.first;
		int B = edge.second.second;
		pq.pop();

		if (find(A) != find(B)) {
			merge(A, B);
			answer += val;
		}
	}
	cout << answer;
}
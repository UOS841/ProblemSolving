#include<iostream>
#include<set>
using namespace std;

int parent[10001];

int find(int u){
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
		
	if (u != v) parent[u] = v;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;
	
	while (M--) {
		int node1, node2;
		cin >> node1 >> node2;

		merge(node1, node2);
	}

	set<int> cc;
	for (int i = 1; i <= N; i++) {
		//cout << parent[i]<<" ";
		cc.insert(find(i));
	}

	cout << cc.size();
}
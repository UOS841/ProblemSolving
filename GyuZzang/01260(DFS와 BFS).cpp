#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
	int N, M, V; // # of node, edge, starting point
	vector<vector<int>> graph;
	queue<int> q;
	stack<int> st;
	vector<int> visited;
	cin >> N >> M >> V;
	graph.resize(N + 1);
	visited.resize(N + 1, 0);

	while (M--) {
		//cout << graph.size();
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	st.push(V);
	cout << V<<" ";
	visited[V] = 1;
	while (!st.empty()) {
		int now = st.top();
		int i;
		for (i = 0; i < graph[now].size(); i++) {
			if (!visited[graph[now][i]]) {
				st.push(graph[now][i]);
				cout << graph[now][i] << " ";
				visited[graph[now][i]] = 1;
				break;
			}
		}
		if (i == graph[now].size()) st.pop();
	}

	cout << endl;
	for (int k = 0; k <= N; k++) {
		visited[k] = 0;
	}

	q.push(V);
	cout << V << " ";
	visited[V] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			if (!visited[graph[now][i]]) {
				q.push(graph[now][i]);
				cout << graph[now][i] << " ";
				visited[graph[now][i]] = 1;
			}
		}
	}

}
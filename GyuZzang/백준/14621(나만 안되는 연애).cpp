#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[1001];
bool check;

struct edge {
	int start;
	int end;
	int distance;
};

bool dist_cmp(edge e1, edge e2) {
	return e1.distance < e2.distance;
}

int find(int u)
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	check = false;
	u = find(u);
	v = find(v);

	//check cycle
	if (u == v) return;

	parent[u] = v;
	check = true;
}


int main() {
	vector<char> gender;
	vector<bool> visited;
	int N, M, tot_dist=0;
	vector<edge> edges;

	cin >> N >> M;
	gender.resize(N);
	visited.resize(N,0);

	for (int i = 0; i < N; i++) {
		cin >> gender[i];
		parent[i] = i;

	}

	while (M--) {
		int s, e, d;
		cin >> s >> e >> d;
		s--; e--;
		if (gender[s] == gender[e]) continue;
		else edges.push_back({ s,e,d });
	}

	sort(edges.begin(), edges.end(), dist_cmp);

	for (edge e:edges)
	{
		//cout << e.distance;
		merge(e.start, e.end);
		if (check) {
			tot_dist += e.distance;
			visited[e.start] = 1;
			visited[e.end] = 1;
		}
	}
	for (bool i : visited) {
		if (!i) {
			cout << -1;
			return 0;
		}
	}
	cout << tot_dist;
}
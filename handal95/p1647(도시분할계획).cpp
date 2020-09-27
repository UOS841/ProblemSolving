#include <iostream>
#include <vector>
#include <queue>


using namespace std;
typedef pair<int, pair<int, int>> Edge;


vector<int> parents;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int find(int x) {
	if (x == parents[x])
		return x;
	return parents[x] = find(parents[x]);
}

void merge(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	if (root_a == root_b)
		return;
	parents[root_b] = root_a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int N,	// The number of Houses 2 <= N <= 10^5
		M;  // The number of roads  1 <= M <= 10^6
	cin >> N >> M;
	parents.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int A, B,  // The index of house A and B
			C;	   // The cost of road between A and B
				   // 1 <= C <= 10^3

		cin >> A >> B >> C;
		pq.push(make_pair(C, make_pair(A, B)));
	}

	long ans = 0;
	int lastVal = 0;
	while (!pq.empty()) {
		Edge edge = pq.top();
		int val = edge.first;
		int A = edge.second.first;
		int B = edge.second.second;
		pq.pop();
		if (find(A) != find(B)) {
			merge(A, B);
			ans += val;
			lastVal = val;
		}
	}
	ans = ans - lastVal;
	cout << ans;
}
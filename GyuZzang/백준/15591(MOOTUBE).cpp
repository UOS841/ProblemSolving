#include<iostream>
#include<vector>
#include<stack>

#define INF 1000000001

using namespace std;

int calculate_min(stack<int> st, vector<vector<int>> usado) {
	int n = st.size() - 1;
	int min = INF;
	while (n--) {
		int now = st.top();
		st.pop();
		int next = st.top();

		if (min > usado[now][next]) min = usado[now][next];
	}

	return min;
}
int main() {
	int N, Q;
	vector<vector<int>> usado; //store final usado 
	vector<vector<int>> edges; //linked list for dfs
	stack<int> st;
	vector<int> visited;

	cin >> N >> Q;
	usado.resize(N, vector<int>(N, INF));
	edges.resize(N);

	for (int i = 0; i < N - 1; i++) {
		int p, q;
		cin >> p >> q;

		cin >> usado[p - 1][q - 1];
		usado[q - 1][p - 1] = usado[p - 1][q - 1];

		edges[p - 1].push_back(q - 1);
		edges[q - 1].push_back(p - 1);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j || usado[i][j] != INF) continue;

			//dfs
			while (!st.empty()) st.pop();
			visited.clear();
			visited.resize(N, 0);
			
			st.push(i);
			visited[i] = 1;
			while (1) {
				int now = st.top();
				if (now == j) {
					int min = calculate_min(st, usado);
					usado[i][j] = usado[j][i] = min;
					break;
				}

				int k;
				for (k = 0; k < edges[now].size(); k++) {
					int next = edges[now][k];
					if (visited[next]) continue;
					st.push(next);
					visited[next] = 1;
					break;
				}
				if (k == edges[now].size()) st.pop();
			}
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << usado[i][j] <<" ";
	//	}
	//	cout << endl;
	//}

	while (Q--) {
		int K, V, cnt = -1;
		cin >> K >> V;
		for(int i = 0; i < N; i++) {
			if (usado[V - 1][i] >= K) cnt++;
		}
		cout << cnt << endl;
	}
}
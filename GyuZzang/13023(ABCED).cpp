#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int N, M;
	vector<vector<int>> friends;
	vector<int> visited;
	stack<int> st;
	int ans = 1;

	cin >> N >> M;
	friends.resize(N);
	visited.resize(N, 0);

	while (M--) {
		int person1, person2;
		cin >> person1 >> person2;
		friends[person1].push_back(person2); 
		friends[person2].push_back(person1);
	}

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			visited[k] = 0;
		}
		ans = 1;
		st.push(j);
		//cout << endl;
		visited[j] = 1;
		while (st.size() < 5) {
			int now = st.top();
			//cout << now << " ";
			int i;
			for (i = 0; i < friends[now].size(); i++) {
				if (!visited[friends[now][i]]) {
					st.push(friends[now][i]);
					visited[friends[now][i]] = 1;
					break;
				}
			}
			//cout << st.size() << " ";
			if (i == friends[now].size()) st.pop();
			if (st.empty()) {
				ans = 0;
				break;
			}
		}
		if (ans) {
			cout << ans;
			break;
		}
	}
	if (!ans) {
		cout << ans;
	}
} 
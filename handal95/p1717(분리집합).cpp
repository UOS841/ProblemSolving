#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	int N, // # of the sets
		M; // # of the operations
    cin >> N >> M;
    parent.resize(N+1);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int operation, A, B;
	for (int i = 0; i < M; i++) {
        cin >> operation >> A >> B;

		A = find(A);
		B = find(B);
		if (operation == 0) {
			if (A >= B) {
				parent[A] = B;
			}
			else {
				parent[B] = A;
			}
		}
		else if(operation == 1){
            cout << ( A==B ? "YES\n" : "NO\n");
		}
	}
	return 0;
}
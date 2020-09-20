#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> parent;
vector<int> friends;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
    b = find(b);
	if (a != b) {
        parent[a] = b;
        friends[b] += friends[a];
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
	cin >> T;
	while (T-->0) {
        int F;
		cin >> F;

		parent.resize(2*F);
		for (int i = 0; i < 2*F; i++){
            parent[i] = i;
        }
        
        friends.assign(2*F, 1);

		unordered_map<string, int> id;

		int count = 0;
		for (int i = 0; i < F; i++) {
    		string A, B;
			cin >> A >> B;
			if (id.find(A) == id.end()) {
				id.insert({ A,count++ });
			}
			if (id.find(B) == id.end()) {
				id.insert({ B,count++ });
			}
			merge(id[A], id[B]);
			cout << friends[find(id[A])] << "\n";
		}
	}
}
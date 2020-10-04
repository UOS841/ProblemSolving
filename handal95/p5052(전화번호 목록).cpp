#include<iostream>
#include<string>

#define MAX_NODE 10
using namespace std;

struct Trie {
	Trie* next[MAX_NODE];
	bool finished;

	Trie() {
		finished = false;
		fill(next, next + MAX_NODE, nullptr);
	}

	void insert(char* key) {
		if (*key == '\0') {
			finished = true;
		}
		else {
			int index = *key - '0';
			if (!next[index])
				next[index] = new Trie;
			next[index]->insert(key + 1);
		}
	}

	bool contains(char* key) {
		int index = *key - '0';
		if (finished || (*key == '\0' && !finished)) {
			return false;
		}

		if (next[index] == nullptr)
			return true;

		return next[index]->contains(key + 1);
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		bool flag = true;
		Trie* trie = new Trie();
		for (int i = 0; i < N; i++) {
			char str[11];
			cin >> str;
			if (!flag)
				continue;

			flag = trie->contains(str);
			trie->insert(str);
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}
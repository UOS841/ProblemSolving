#include<iostream>
#include<string>

#define MAX_NODE 26
using namespace std;


struct Trie {
	Trie* next[MAX_NODE];
	bool finished;
	int count;

	Trie() {
		fill(next, next + MAX_NODE, nullptr);
		finished = false;
		count = 0;
	}

	void insert(char* key) {
		if (*key == '!') {
			finished = true;
		}
		else {
			int index = *key - 'a';
			if (!next[index]) {
				next[index] = new Trie;
				count++;
			}
			next[index]->insert(key + 1);
		}
	}

	bool contains(char* key) {
		int index = *key - 'a';
		if (*key == '!' && !finished) {
			cout << "yes1" << endl;
			return false;
		}

		if (finished) {
			cout << "yes2" << endl;
			return false;
		}

		if (next[index] == nullptr)
			return true;

		return next[index]->contains(key + 1);
	}

	void printCount(char* key) {
		int index = *key - 'a';
		if (*key == '!') {
			return ;
		}
		cout << *key << "'s idx num :" << count << endl;
		next[index]->printCount(key + 1);
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		string str;
		getline(cin, str);
		if (str == "") break;
		
		int N = stoi(str);
		Trie trie = Trie();
		for (int i = 0; i < N; i++) {
			char word[81];
			fill(word, word + 81, '!');
			cin >> word;
			trie.insert(word);
			trie.printCount(word);
		}
	}
}
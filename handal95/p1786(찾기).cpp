#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_fail(string str) {
	int str_length = str.size();
	vector<int> fail(str_length, 0);
	for (int i = 1, j = 0; i < str_length; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = fail[j - 1];
		}
		if (str[i] == str[j]) {
			fail[i] = ++j;
		}
	}
	return fail;
}


vector<int> KMP(string text, string pattern) {
    int text_len = text.length();
    int pattern_len = pattern.length();
    
	vector<int> fail = get_fail(pattern);
	vector<int> found;
	for (int i= 0, j= 0; i < text_len; i++) {
        // i :    text 에서의 iterator
        // j : pattern 에서의 iterator
		while (j > 0 && text[i] != pattern[j]) {
			j = fail[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattern_len - 1) {
				j = fail[j];
				found.push_back((i - pattern_len + 2));
			}
			else {
				j++;
			}
		}
	}
	return found;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string T,   // Text String
		   P;   // Pattern String
	getline(cin, T);
	getline(cin, P);

	vector<int> found = KMP(T, P);

	cout << found.size() << "\n";
	for (int ans : found) {
		cout << ans << "\n";
	}
}
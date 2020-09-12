#include <iostream>


using namespace std;


using namespace std;


int main() {
   	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int alphabets[26];
	int size = sizeof(alphabets) / sizeof(int);
	fill_n(alphabets, size, -1);

	int len = str.length();
	for (int i = 0; i < len; i++) {
		char ch = str.at(i)-'a';
		if (alphabets[ch] == -1) {
			alphabets[ch] = i;
		}
	}

	for (int loc : alphabets) {
		cout << loc << " ";
	}

	return 0;
}
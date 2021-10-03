#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int L, C, //length of password, # of alphabet
		n_vowel, n_consonant; //# of 모음, 자음
	string password;
	vector<char> alphabets;
	vector<bool> permutation;
	
	cin >> L >> C;
	alphabets.resize(C);
	permutation.resize(C, 1);

	for (int i = 0; i < L; i++) {
		permutation[i] = 0;
	} //0 -> select, 1 -> not select
	
	for (int i = 0; i < C; i++) {
		cin >> alphabets[i];
	}

	sort(alphabets.begin(), alphabets.end());

	do {
		n_consonant = n_vowel = 0;
		password = "";
		for (int i = 0; i < C; i++) {
			if (!permutation[i]) {
				password.push_back(alphabets[i]);
				switch (alphabets[i]) {
				case 'a': case 'e': case 'i': case 'o': case 'u':
					n_vowel++; break;
				default: 
					n_consonant++; break;
				}
			}
		}
		if (n_vowel > 0 && n_consonant > 1) cout << password << endl;

	} while (next_permutation(permutation.begin(), permutation.end()));

	
}
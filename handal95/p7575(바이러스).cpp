#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> Pattern;
typedef vector<int> Code;

vector<int> get_fail(vector<int> program) {
	int size = program.size();
	vector<int> fail(size, 0);
	for (int i = 1, j = 0; i < size; i++) {
		while (j > 0 && program[i] != program[j]) {
			j = fail[j - 1];
		}
		if (program[i] == program[j]) {
			fail[i] = ++j;
		}
	}
	return fail;
}


vector<Pattern> KMP(vector<int> program, vector<Pattern> patterns, int K) {
	vector<Pattern> new_patterns(0, vector<int>(K+1, 0));
	int count = 0;
	for (int p = 0; p < patterns.size(); p++) {
		vector<int> fail = get_fail(patterns[p]);

		for (int i = 0, j = 0; i < program.size(); i++) {
			while (j > 0 && program[i] != patterns[p][j]) {
				j = fail[j - 1];
			}
			if (program[i] == patterns[p][j]) {
				if (j >= K-1) {
					j = fail[j];
					vector<int> v(patterns[p].begin(), patterns[p].end());
					new_patterns.push_back(v);
					break;
				}
				else {
					j++;
				}
			}
		}
	}

	return new_patterns;
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int N,
		K;
	cin >> N >> K;
	vector<Code> programs(N, Code());

	int len;
	cin >> len;
	programs[0].assign(len, 0);
	for (int j = 0; j < len; j++) {
		cin >> programs[0][j];
	}

	for (int i = 1;i < N;i++) {
		cin >> len;
		programs[i].assign(2 * len + 1, 0);
		for (int j = 0; j < len; j++) {
			cin >> programs[i][j];
			programs[i][2 * len - j] = programs[i][j];
		}
	}

	int size = programs[0].size() - K + 1;
	vector<Pattern> patterns(size, Pattern(K+1, 0));
	for (int p = 0; p < size; p++) {
		patterns[p].assign(programs[0].begin()+p, programs[0].begin()+p+K);
	}

	for (int i = 1; i < N; i++) {
		patterns = KMP(programs[i], patterns, K);
	}

    cout << (patterns.size() > 0 ? "YES" : "NO");
}
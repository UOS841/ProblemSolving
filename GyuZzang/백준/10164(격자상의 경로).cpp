#include<iostream>
#include<vector>
#include<cstdlib> 
#include<algorithm>

using namespace std;

unsigned long long get_factorial(int n) {
	unsigned long long res = 1;
	while (n) {
		res *= n;
		n--;
	}
	return res;
}

unsigned long long get_n_dist_case(int r1, int r2, int c1, int c2) {
	int molecule = abs(r1 - r2) + abs(c1 - c2);
	int denominator = max(abs(r1 - r2), abs(c1 - c2));
	unsigned long long res = 1;

	while (molecule > denominator) { //(r+c)!/c!/r! --> problem: range of type (max 28!)
		res *= molecule;
		molecule--;
	}
	return res/get_factorial(min(abs(r1 - r2), abs(c1 - c2)));
}

int main() {
	int N, M, K,
		k_row, k_col;
	cin >> N >> M >> K;

	if (K) {
		k_row = (K-1) / M;
		k_col = K - 1 - (k_row) * M;

		//cout << "row" << k_row << "col" << k_col << endl;
		cout << get_n_dist_case(0, k_row, 0, k_col) * get_n_dist_case(N - 1, k_row, M - 1, k_col);

		return 0;
	}

	cout << get_n_dist_case(0, N - 1, 0, M - 1);

	return 0;
}
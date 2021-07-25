#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;

	cin >> n;

	while (n--) {
		string input, ans;
		int check_once = 0;

		cin >> input;

		do {
			ans = input;
			if (check_once++) break;
		} while (next_permutation(input.begin(), input.end()));
		
		cout << ans << endl;
	}
}
#include <iostream>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;	    // Test case
	cin >> T;

	while (T-->0) {
		bool ans = true;
		string str;
		cin >> str;

		int stack = 0;
        int len = str.length();
		for (int i = 0; i < len && stack >= 0; i++) {
            char ch = str.at(i);
			if (ch == '('){
				stack++;
            }
			else if (ch == ')'){
				stack--;
            }
		}
        
		if (stack != 0) {
			ans = false;
		}

		cout << (ans ? "YES" : "NO");
	}

    return 0;
}
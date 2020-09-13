#include <iostream>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int ans = 0;
	int stack = 1;
    int len = str.length();
	for (int i = 1; i < len; i++) {
		char cur = str.at(i);
		char prev = str.at(i - 1);
        
		if (cur == '(') {
			stack++;
		}
		else if (cur == ')') {
			stack--;
			if (prev == '(') {
				ans += stack - 1;
			}
			ans++;
		}
	}
	cout << ans;
    
	return 0;
}
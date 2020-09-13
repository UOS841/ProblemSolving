#include <iostream>
#include <stack>
#include <queue>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);
    
	int N;
	cin >> N;

	stack<int> stack;
	stack.push(0);

	int cur;
	int max = 0;
	queue<char> ans;
    while(N-->0){
		cin >> cur;

		if (cur > max) {
			for (int i = max + 1; i <= cur; i++) {
				stack.push(i);
				ans.push('+');
			}
		}
		else if (cur != stack.top()) {
			cout << "NO\n";
			return 0;
		}

		stack.pop();
		ans.push('-');
		if (max < cur) {
			max = cur;
		}
	}
	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}
	return 0;
}
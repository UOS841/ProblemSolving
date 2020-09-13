#include <iostream>
#include <queue>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	priority_queue<string, vector<string>, greater<string>> pq;
	
	int len = str.length();
	for (int i = 0; i < len; i++) {
		pq.push(str.substr(i, len));
	}

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
    
    return 0;
}
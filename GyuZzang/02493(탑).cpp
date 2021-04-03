#include<iostream>
#include<stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	stack<pair<int,int>> tops;

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;

		while (!tops.empty() && tops.top().second < height) {
			tops.pop();
		}
		if (tops.empty()) cout << "0 ";
		else cout << tops.top().first << " ";

		tops.push({ i,height });
	}
}
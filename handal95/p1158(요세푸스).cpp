#include <iostream>
#include <queue>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N,  // N is Number 
        K;  // K is Interval
	cin >> N >> K;

	queue<int> que;
	for (int i = 1; i <= N; i++)
		que.push(i);

	int cnt = 1;
	cout << "<";
	while (que.size() > 1) {
		for (int i = 1; i < K; i++) {
			que.push(que.front());
			que.pop();
		}
		cout << que.front() << ", ";
		que.pop();
	}
	cout << que.front() << ">";
	que.pop();

    return 0;
}
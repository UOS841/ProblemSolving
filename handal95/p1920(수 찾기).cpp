#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
    int val;
    cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
        cin >> v[i];

	sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++){
		cin >> val;
        int flag = binary_search(v.begin(), v.end(), val);
		cout << flag<<"\n";
	}
	return 0;
}
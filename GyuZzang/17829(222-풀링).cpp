#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get_second_max(int a1,int a2, int a3, int a4) { //두번째로 큰 값 출력
	vector<int> a({ a1,a2,a3,a4 });
	sort(a.begin(), a.end());
	return a[2];
}

int main() {
	int N;
	vector<vector<int>> conv;
	cin >> N;
	conv.resize(N);

	for (int i = 0; i < N; i++) {
		conv[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> conv[i][j];
		}
	}

	int t = 2; //t= 2 -> 4 -> 8 ...
	int second_max;

	while (t <= N) {
		for (int i = 0; i < N; i += t) {
			for (int j = 0; j < N; j += t) {
				second_max = get_second_max(conv[i][j], conv[i][j + t/2], conv[i + t / 2][j], conv[i + t / 2][j + t / 2]);
				conv[i][j] = second_max; //대표값을 i,j로 가정.
			}
		}
		t *= 2;
	}

	cout << conv[0][0];
}

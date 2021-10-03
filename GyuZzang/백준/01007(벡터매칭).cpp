#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	cout << fixed;
	cout.precision(7);
	while (T--) {
		int N,
			sum_x = 0, sum_y = 0;

		vector<pair<int, int>> points;

		vector<int> comb;

		long long min = -1, now;

		cin >> N;
		points.resize(N);
		comb.resize(N, 0);

		for (int i = 0; i < N; i++) {
			cin >> points[i].first >> points[i].second;
			if (i >= N / 2) comb[i] = 1;
		}

		//brute force(¿ÏÀüÅ½»ö)
		do {
			sum_x = sum_y = 0;
			for (int i = 0; i < N; i++) {
				if (comb[i]) {
					sum_x += points[i].first;
					sum_y += points[i].second;
				}
				else {
					sum_x -= points[i].first;
					sum_y -= points[i].second;
				}
			}
			//cout << "x: " << sum_x << ", y: " << sum_y << endl;
			now = pow(sum_x,2) + pow(sum_y,2);
	
			if (min == -1 || min > now) min = now;
			//cout << min << endl;

		} while (next_permutation(comb.begin(), comb.end()));
		//# of plus == # of minus --> min of vector size

		cout << sqrt(min) << endl;
		points.clear();
	}
}
//16*10^8
//4000000
//1 2 3 4
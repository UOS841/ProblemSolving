#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int get_distance(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		int x1, y1, x2, y2, n;
		vector<pair<pair<int, int>, int>> planets;
		int start, end, ans = 0;

		cin >> x1 >> y1 >> x2 >> y2 >> n;
		planets.resize(n);


		for (int i = 0; i < n; i++) {
			cin >> planets[i].first.first >> planets[i].first.second >> planets[i].second;
		}

		//두 점이 어떤 행성계 속하는지 확인, 공통행성은 고려x, 나머지 행성 개수 더하기
		for (auto p : planets) {
			start = end = 0;
			if (p.second > get_distance({ x1, y1 }, p.first)) start = 1;
			if (p.second > get_distance({ x2, y2 }, p.first)) end = 1;
			ans += start ^ end;
		}

		cout << ans << endl;

	}
		
}
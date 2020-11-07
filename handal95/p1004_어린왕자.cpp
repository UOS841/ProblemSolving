#include <iostream>
#include <cmath>

using namespace std;

long long get_distance(int x, int y, int r){
    return pow(x, 2) + pow(y, 2) - pow(r, 2);
}

int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int from[2],
			dest[2],
			point[2];
		cin >> from[0] >> from[1];
		cin >> dest[0] >> dest[1];

		int N;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			long long R;
			cin >> point[0] >> point[1] >> R;
			long long d1 = get_distance((from[0]-point[0]), (from[1]-point[1]), R);
			long long d2 = get_distance((dest[0]-point[0]), (dest[1]-point[1]), R);

			if (d1 * d2 < 0)
				ans++;
		}
		cout << ans << "\n";
	}
}
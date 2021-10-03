#include<iostream>
#include<vector>

using namespace std;

vector<long> height;

int is_visible(int x1, int x2) {
	double a = (double)(height[x2] - height[x1]) / (double)(x2 - x1);
	double b = height[x1] - a * x1;
	//y=ax+b
	for (int x = x1 + 1; x < x2; x++) {
		if (height[x] >= a * x + b) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int N;
	vector<int> sight;

	cin >> N;
	height.resize(N);
	sight.resize(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	for (int x1 = 0; x1 < N - 1; x1++) {
		sight[x1]++;
		sight[x1 + 1]++;
		for (int x2 = x1 + 2; x2 < N; x2++) {
			if (is_visible(x1, x2)) {
				sight[x1]++;
				sight[x2]++;
			}
		}
	}
	
	int max = 0;
	for (int i : sight) {
		if (max < i) max = i;
	}
	cout << max;

}
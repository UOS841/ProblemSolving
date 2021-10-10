#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	long long N, M, //# of trees, total tree length
		height_right, height_left, height_mid;
	long long sum_length, result = 0;
	vector<long long> trees;

	cin >> N >> M;
	trees.resize(N);
	for (long long i = 0; i < N; i++) {
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end());

	height_right = trees[N - 1];
	height_left = 0;

	while (height_left <= height_right) {
		height_mid = (height_right + height_left) / 2;
		sum_length = 0;
		for (long long i = N - 1; i >= 0 && trees[i] > height_mid; i--) {
			sum_length += trees[i] - height_mid;
		}

		if (M > sum_length) {
			height_right = height_mid - 1;
		}
		else {
			if (result < height_mid) result = height_mid;
			height_left = height_mid + 1;
		}
	}

	cout << result;
}
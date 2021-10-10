#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int now_n, target_n, count_n, result = 0;
	long long length_r, length_l, length_m;
	vector<int> lan_lines;

	cin >> now_n >> target_n;
	lan_lines.resize(now_n);

	for (int i = 0; i < now_n; i++) {
		cin >> lan_lines[i];
	}

	sort(lan_lines.begin(), lan_lines.end());

	length_l = 1;
	length_r = lan_lines[now_n-1];

	while (length_l <= length_r) {
		length_m = (length_l + length_r) / 2;
		count_n = 0;

		for (int i = 0; i < now_n; i++) {
			count_n += lan_lines[i] / length_m;
		}

		if (count_n < target_n) {
			length_r = length_m - 1;
		}
		else {
			if (result < length_m) result = length_m;
			length_l = length_m + 1;
		}
	}

	cout << result;
	
	return 0;
}                                                     
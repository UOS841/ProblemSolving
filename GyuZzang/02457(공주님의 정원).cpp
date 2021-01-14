#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> day; // month to day

void set_day() {
	int cnt = 0;
	day.resize(12);
	for (int i = 1; i <= 12; i++) {
		switch (i) {
		case 4:
		case 6:
		case 9:
		case 11:
			day[i - 1].resize(30);
			break;
		case 2:
			day[i - 1].resize(28);
			break;
		default:
			day[i - 1].resize(31);
		}
		for (int j = 0; j < day[i - 1].size(); j++) {
			day[i - 1][j] = cnt++;
		}
	}
}

int main() {
	int N, res = 0;
	vector<pair<int, int>> flowers;

	cin >> N;
	set_day();

	while (N--) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		flowers.push_back({ day[sm - 1][sd - 1],day[em - 1][ed - 1] });
	}

	int day_now = day[2][0];
	int day_end = day[10][29];
	int max = day_now;

	while (day_now <= day_end) {
		for (auto i : flowers) {
			if (day_now >= i.first && day_now < i.second) {
				if (max < i.second) max = i.second;
			}
		}
		if (day_now == max) {
			cout << 0;
			return 0;
		}
		day_now = max;
		res++;
	}

	cout << res;
}

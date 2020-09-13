#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n;
	int num, min, max;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	min = v[0];
	max = v[0];

	for (int j = 0; j < n; j++) {
		if (min > v[j]) {
            min = v[j];
		}
		if (max < v[j]) {
			max = v[j];
		}
	}

	cout << min << " " << max << endl;

}
#include<iostream>
#include<cmath>

using namespace std;

int main() {
	long long monkey, dog, diff, max = 0, days = 1;
	cin >> monkey >> dog;
	diff = dog - monkey;

	if (diff == 0) {
		cout << 0;
		return 0;
	}

	while (diff > max) {
		long long mid = days / 2 ;
		max = days % 2 ? pow(mid + 1, 2) : pow(mid, 2) + mid;
		days++;
	}

	cout << days-1;
}
#include<iostream>
#include<cmath>

using namespace std;


int main() {
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		double sum = 0;
		while (n) {
			sum += log10l(n);
			n--;
		}
		cout << (int)sum + 1 << endl;
	}
}
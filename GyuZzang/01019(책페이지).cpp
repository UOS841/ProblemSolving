#include<iostream>
#include<string>

using namespace std;

int number[10];

int count_number(long long n) {
	if (!n) return 0;
	string num = to_string(n);
	for (char c : num) {
		number[c - '0']++;
	}
	return 1;
}

int main() {
	long long N;
	cin >> N;

	while (count_number(N--));

	for (int i : number) {
		cout << i << " ";
	}
}
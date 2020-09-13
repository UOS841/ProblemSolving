#include <iostream>
#include <math.h>
#include <string>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

	string A, B, C, D;
	cin >> A >> B >> C >> D;

	long long first = stoi(A) * pow(10, B.size()) + stoi(B);
	long long second = stoi(C) * pow(10, D.size()) + stoi(D);
	long long answer = first + second;
	cout << answer;
	return 0;
}
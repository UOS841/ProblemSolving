#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main() {
	char pw[61];
	int cnt = 0;//# of 1,2,6,7
	long long k;

	cin >> pw;
	cin >> k;

	//count 1,2,6,7
	for (int i = 0; i < strlen(pw); i++) {
		if (pw[i] == '1' || pw[i] == '6' || pw[i] == '2' || pw[i] == '7') {
			cnt++;
		}
	}

	//not exist 'k'th pw
	long long tot = pow(2, cnt);
	if (tot < k || k < 1) {
		cout << "-1";
	}
	else
	{
		k--;
		//set 1,2,6,7
		for (int i = strlen(pw) - 1; i>=0 ; i--) {
			if (pw[i] == '1' || pw[i] == '6') {
				if (k & 1) pw[i] = '6';
				else pw[i] = '1';
				k >>= 1;
			}
			else if (pw[i] == '2' || pw[i] == '7') {
				if (k & 1) pw[i] = '7';
				else pw[i] = '2';
				k >>= 1;
			}
		}
		cout << pw;
	}


}
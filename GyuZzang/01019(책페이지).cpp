#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int number[10];
int number_ans[10];

//int count_number(long long n) {
//	if (!n) return 0;
//	string num = to_string(n);
//	for (char c : num) {
//		number_ans[c - '0']++;
//	}
//	return 1;
//}

int main() {
	long long n;
	int position=0; //position=ÀÚ¸´¼ö
	cin >> n;
	if (n < 10) {
		for (int i = 0; i <10; i++) {
			if(i&& i<=n) cout << 1 << " ";
			else cout << 0 << " ";
		}
		return 0;
	}
	int p, cnt, now;
	while (1) {
		p = pow(10, position);
		cnt = n / (p * 10);
		if (!cnt) break;
		now = (n%(p*10)) / p;

		//except 0 ~ p-1
	    number[0] -= p;

		for (int i = 0; i < 10; i++) {
			if (i > now) number[i] += (cnt * p);
			else if(i < now) number[i] += (cnt * p + p);
			else number[i] += (cnt * p + n % p + 1);
		}
		position++;
	}
	now = (n % (p * 10)) / p;
	for (int i = 1; i <=now; i++) {
		if (i < now) number[i] += p;
		else number[i] += (n % p + 1);
	}
	//while (count_number(n--));

	for (int i : number) {
		cout << i << " ";
	}
	cout << endl;
	//for (int i : number_ans) {
	//	cout << i << " ";
	//}
}

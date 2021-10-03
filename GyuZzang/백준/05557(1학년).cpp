#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, ans; //# of left num, right num
	vector<int> num;
	vector<int> tmp1; //0~20 경우의 수 저장 dp
	vector<int> tmp2;
	vector<int> init;

	tmp1.resize(21, 0);
	tmp2.resize(21, 0);
	init.resize(21, 0);

	cin >> N;
	N--;
	num.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> ans;

	tmp1[num[0]]++;
	for (int i = 1; i < N; i++) {
		tmp2 = tmp1;
		tmp1 = init;
		for (int j = 0; j <= 20; j++) {
			if (!tmp2[j]) continue;

			//0 to 20
			if (j + num[i] <= 20)tmp1[j + num[i]] += tmp2[j];
			if (j - num[i] >= 0) tmp1[j - num[i]] += tmp2[j];

		}
	}

	cout << tmp1[ans];

}
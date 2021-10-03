#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;


int main() {
	int N;
	int Min[2][3]; //index 0 : prev, index 1 : now
	int Max[2][3];

	cin >> N;

	cin >> Max[0][0] >> Max[0][1] >> Max[0][2];
	for (int j = 0; j < 3; j++) Min[0][j] = Max[0][j];

	for (int i = 1; i < N; i++) {

		cin >> Max[1][0] >> Max[1][1] >> Max[1][2];

		//set min
		Min[1][0] = Max[1][0] + min(Min[0][0], Min[0][1]);
		Min[1][1] = Max[1][1] + min(Min[0][0], min(Min[0][1], Min[0][2]));
		Min[1][2] = Max[1][2] + min(Min[0][1], Min[0][2]);

		//set max
		Max[1][0] += max(Max[0][0], Max[0][1]);
		Max[1][1] += max(Max[0][0], max(Max[0][1], Max[0][2]));
		Max[1][2] += max(Max[0][1], Max[0][2]);

		//now to prev
		for (int j = 0; j < 3; j++) {
			Min[0][j] = Min[1][j];
			Max[0][j] = Max[1][j];
		}
	}

	cout<< max(Max[0][0], max(Max[0][1], Max[0][2])) <<" "<< min(Min[0][0], min(Min[0][1], Min[0][2]));
	
}
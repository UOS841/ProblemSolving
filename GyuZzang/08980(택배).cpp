#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int C, N, M; //용량, 마을 수, 박스 정보 수
	vector<vector<int>> boxes;
	int sum, res=0;
	cin >> N >> C >> M;

	boxes.resize(N,vector<int>(N,0));
	while(M--) {
		int s, e;
		cin >> s >> e;
		cin >> boxes[s - 1][e - 1];
	}

	for (int i = 0; i < N-1; i++) {
		if(i==0) sum = 0;
		else {
			for (int k = 0; k < i; k++) {
				cout << "-" << boxes[k][i];
				sum -= boxes[k][i];
			}
		}
		cout << "S"<<sum << endl;
		for (int j = i+1; j < N; j++) {
			if (sum < C) {
				sum += boxes[i][j];
				if (sum > C) {
					boxes[i][j] = boxes[i][j] - (sum - C);
					sum=C;
				}
			}
			else {
				boxes[i][j] = 0;
			}
			res += boxes[i][j];
			cout << boxes[i][j] << endl;
		}
	}


	cout << res;
}
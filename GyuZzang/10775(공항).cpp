#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int G, P, g, cnt = 0;
	vector<int> gate;
	
	cin >> G >> P;
	gate.resize(G + 1);

	for (int i = 0; i <= G; i++) {
		gate[i] = i ;
	}

	while (P--) {
		cin >> g;
		
		if (upper_bound(gate.begin(), gate.end(), g) - gate.begin() - 1) {
			gate.erase(upper_bound(gate.begin(), gate.end(), g) - 1);
			cnt++;
		}
		else {
			break;
		}
		//for (int i : gate) cout << i<<" ";

	}
	cout << cnt;
	
}
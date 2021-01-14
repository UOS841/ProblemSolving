#include<iostream>
#include<vector>

using namespace std;

int main() {
	int G, P, g, cnt = 0;
	vector<bool> gate;
	
	cin >> G >> P;
	gate.resize(G + 1, 0);

	while (P--) {
		cin >> g;
		int i;
		for (i = g; i > 0; i--) {
			if (!gate[i]) {
				gate[i] = 1;
				cnt++;
				break;
			}
		}
		if (!i) break;

	}
	cout << cnt;
	
}
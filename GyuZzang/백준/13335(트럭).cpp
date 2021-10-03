#include<iostream>
#include<vector>

using namespace std;

struct Truck {
	int weight;
	int time_on_bridge = 0;
};

int main() {
	int n, w, l; //# of truck, length of bridge, max weight of bridge
	int time = 0, weight_sum = 0, next_truck_idx = 0, start_truck_idx = 0;
	vector<Truck> trucks;

	cin >> n >> w >> l;
	trucks.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> trucks[i].weight;
	}

	//count times until last truck enter the bridge
	while (next_truck_idx < n) {
		if (weight_sum + trucks[next_truck_idx].weight <= l) {
			weight_sum += trucks[next_truck_idx].weight;
			next_truck_idx++;
		}

		for (int i = start_truck_idx; i < next_truck_idx; i++) {
			trucks[i].time_on_bridge++;
			if (trucks[i].time_on_bridge >= w) {
				//cout << trucks[i].time_on_bridge << endl;
				//cout << "time:" << time << ", end:" << i<<endl;
				weight_sum -= trucks[i].weight;
				start_truck_idx++;
			}
		}

		time++;
	}

	cout << time + w;
}
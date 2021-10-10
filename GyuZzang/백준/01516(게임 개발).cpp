#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct building {
	int time;
	int prev_time=0;
	vector<int> prev;
};

vector<building> buildings;

int main() {
	int N;
	queue<int> tplg_q;
	vector<int>indegree;

	cin >> N;
	indegree.resize(N,0);
	buildings.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> buildings[i].time;
		int prev;
		while (1) {
			cin >> prev;
			if (prev == -1) break;
			buildings[prev - 1].prev.push_back(i);
			indegree[i]++;
		}
		if (!indegree[i]) tplg_q.push(i);
	}

	while (!tplg_q.empty()) {
		int now = tplg_q.front();
		tplg_q.pop();

		for (int next : buildings[now].prev) {
			indegree[next]--;
			if (indegree[next] == 0) {
				tplg_q.push(next);
			}
			int tot_time = buildings[now].time + buildings[now].prev_time;
			if (tot_time > buildings[next].prev_time) {
				buildings[next].prev_time = tot_time;
			}
		}
		
	}

	for (building b : buildings) {
		cout << b.time + b.prev_time << endl;
	}


}
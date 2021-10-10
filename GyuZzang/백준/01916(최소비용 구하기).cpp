#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

#define MAX INT_MAX

int main() {
	int N, M;
	vector<vector<pair<int,int>>> bus; //(cost,end)
	vector<int> dist;
	int start, end;
	priority_queue<pair<int, int>> pq; //(cost,dest)

	cin >> N >> M;
	bus.resize(N);
	dist.resize(N,MAX);

	while (M--) {
		int cost;
		cin >> start >> end >> cost;
		bus[start - 1].push_back({ cost,end-1 });
	}

	cin >> start >> end;
	start--;
	end--;
	//dist = bus[start];
	//for (int i = 0; i < N; i++) {
	//	bus[i][i] = 0;
	//	for (int j = 0; j < N; j++) {
	//		if (bus[i][j] == MAX || i == j) continue;
	//		for (int k = 0; k < N; k++) {
	//			if (bus[j][k] == MAX || j == k) continue;
	//			if (bus[i][k] > bus[i][j] + bus[j][k])
	//				bus[i][k] = bus[i][j] + bus[j][k];
	//		}
	//	}
	//}


	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		//cout << "while" << endl;
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < bus[now].size(); i++) {
			int next = bus[now][i].second;
			if (dist[next] > cost + bus[now][i].first) {
				dist[next] = cost + bus[now][i].first;
				pq.push({ -dist[next],next });
				//cout << "push " << dest<< i<< cost << endl;
			}
		}

	}
	cout << dist[end];
}
// 거노교수님 코드 리뷰

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {

	int
		i, // indexer
		size, // size of a vector
		cost, // cost next build a building
		now, next, // building
		T, // the number of test case
		N, // the number of buildings
		K, // the number of rules for building
		D, // time next spend next build
		X, Y, // order of build
		W; // the building number next vicnextry


	vector<vector<int>> buildings; // [[건물 짓는 시간], 이전 건물 짓는 시간 총 합, 다음 짓어야할 건물들(추가 가능)]]
    vector<int> remained_n_buildings; // 짓기 전 남아있는 건물
	queue<int> visiting_queue; // 건물 지어지면 pop 

/*
    buildings = [ 
        [], // i = 1부터 시작해서 0번 무시
        [10,0,2,3],
        [1, 10, 4],
        [100, 10, 4],
        [10,110],
    ]
*/




	// get data: the number of test case
	cin >> T;
	while (T--) {
		cin >> N >> K;

        // *** 초기화 단계 ***
		// init {buildings}
		size = buildings.size();
		while (size--) buildings[size].clear();
		buildings.clear();
		buildings.resize(N + 1, vector<int>(2));

		// init {remained_n_buildings}
		remained_n_buildings.clear();
		remained_n_buildings.resize(N + 1, 0);

		// init {visiting_queue}
		size = visiting_queue.size();
		while (size--) visiting_queue.pop();

        // *** 초기화 단계 ***

		// set cost of each building
		for (i = 1; i <= N; i++) {
			cin >> buildings[i][0];
			buildings[i][1] = 0;
		}

		// set order of build
		while (K--) {
			cin >> X >> Y;
			buildings[X].push_back(Y);
			remained_n_buildings[Y]++;
		}

		// find all starter buildings
		for (i = 1; i <= N; i++) {
			if (remained_n_buildings[i] == 0) {
				visiting_queue.push(i);
			}
		}

		// set the building number next vicnextry
		cin >> W;
		while (true) {
			// pop one
			now = visiting_queue.front();
			cost = buildings[now][0] + buildings[now][1];
			size = buildings[now].size();
			// 건물 지으면 pop
            visiting_queue.pop();

            // 백준이가 지을 건물에 도달하면 끗
			if (now == W) {
				cout << cost << '\n';
				break;
			}

			for (i = 2; i < size; i++) { // siz
                // 다음에 지을 건물 원소
				next = buildings[now][i];

				// update maximum cost for pre-construct building
				if (buildings[next][1] < cost)
					buildings[next][1] = cost;

				remained_n_buildings[next]--;
				if (remained_n_buildings[next] == 0) {
					visiting_queue.push(next);
				}
			}
		}
	}

	return 0;
}
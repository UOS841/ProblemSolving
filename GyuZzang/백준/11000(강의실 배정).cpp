#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool lecture_compare(pair<int,int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

struct compare {
	bool operator()(pair<int,int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};	


int main() {
	int N, res = 0;
	vector<pair<int, int>> lectures;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> used_lectures;

	cin >> N;
	lectures.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> lectures[i].first >> lectures[i].second;
	}

	sort(lectures.begin(), lectures.end(), lecture_compare);

	for (int i = 0; i < N; i++) {
		if (used_lectures.empty() || used_lectures.top().second > lectures[i].first) {
			used_lectures.push(lectures[i]);
			res++;
		}
		else {
			used_lectures.pop();
			used_lectures.push(lectures[i]);
		}
	}
	
	cout << res;
}
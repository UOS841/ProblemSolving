#include <iostream>
#include <vector>
using namespace std;

const int n = 1000;     // 왜?   

int N, M,                    // N: 가수 수, M: PD 수
    indegree[n];
vector<int> result;          // 값 저장 배열  
vector<int> v[n];         	 // 뒤 이어 올 노드

void musicOrder(int now) {		
	indegree[now] = 1;      
	result.push_back(now);
    // 범위 기반 for 문
	for (int next : v[now])
		if (!(--indegree[next])){ 
            musicOrder(next);
        }
}

int main() {
	int i, j,               // index 
        pdNum,              // pd가 담당하는 가수 수
        first,              // 처음 노드
        next;               // 다음 노드
	cin >> N >> M;
	while (M--) {           // 전체 pd의 수만큼 반복
		cin >> pdNum >> first;
		while (--pdNum) {   
			cin >> next;    // 
			v[first].push_back(next); // 첫 노드 뒤에 다음 노드 추가
			indegree[next]++;           // 간선 배열에 노드번 째 추가
			first = next;               // ???
		}
	}
	for (i = 1; i <= N; i++)
		if (!indegree[i]) musicOrder(i);
	
	if (result.size() < N) cout<<0;
	else {
        for (int p : result) {
            cout<<p<<endl;
        }
    }
	return 0;
}
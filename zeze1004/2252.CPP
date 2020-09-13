#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int indegree[32001];            // 입력(진입)차수 기록
vector<int> v[32001];           // 정점들의 기록

int main() {
    int N, M, a, b;             // a 정점이 b 정점들로 향함
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>a>>b;
        indegree[b]++;          // 진입차수 카운팅 아아아아ㅏ 기억나따 
                                // 긍게
                                // 1 -> 3 : 진입차수 증가
                                // 2 -> 3
                                // [0,0,0,2,...]

        v[a].push_back(b);      // a 정점이 향한 정점 b들을 추가
                                // [[],[3],[3],...]
    }
    queue<int> now;             // queqe
                                 
    for (int i = 1; i <= N; i++) { 
        if(indegree[i] == 0) {  // 최초 진입차수가 0인 정점들 큐에 삽입
                                // [X,0,0,2,...]

            now.push(i);        // 1,2 원소 삽입
        }      
    }

    while(!now.empty()){        // 큐가 비어있을 때까지 호호
        int i = now.front();    // 큐 젤 앞에 있는 원소 반환
        now.pop();              // 제거 후 반환

        cout<<i<<" ";           // 1

        for(int j = 0; j< v[i].size();j++){     // [[],[3],[3],...] -> size 1
            // 
            if(--indegree[v[i][j]]==0)          // [0,0,0,2,...] -> 하나씩 빼서 0 만듦
                now.push(v[i][j]);              // 이게 모지...?
        }
    }
    return 0;
}
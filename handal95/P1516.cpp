#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;
    // require size , { index, time }
    vector<pair<int, pair<int, int>>> buildings(N + 1, {0, {0, 0}});
    vector<vector<int>> next(N + 1, vector<int>());
    vector<int> required_count(N + 1, 0);

    int val = 0;
    for(int i = 1; i <= N; i++){
        buildings[i].second.first = i; 
        cin >> buildings[i].second.second;
        while(true){
            cin >> val;
            if(val == -1)
                break;

            required_count[i]++;
            next[val].push_back(i);
            buildings[i].first++;
        }
    }

    queue<int> q;
    vector<int> answer(N+1, 0);
    for(int i = 1; i <= N; i++){
        if(required_count[i] == 0){
            answer[i] = buildings[i].second.second;
            q.push(i);
        } 
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i = 0; i < next[cur].size(); i++){
            int nxt = next[cur][i];

            answer[nxt] = max(answer[nxt], answer[cur] + buildings[nxt].second.second);
            required_count[nxt]--;

            if(required_count[nxt] == 0)
                q.push(nxt);
        }
    }

    for(int i = 1; i<= N; i++){
        cout << answer[i] << endl;
    }
}
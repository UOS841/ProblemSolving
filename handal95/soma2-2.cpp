#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> next(N);
    vector<bool> fan_in(N, false);

    int cur = 0;
    int cur_possible = 0;
    int prev_possible = 0;
    for(int i = 0; i < N; i++){
        int val;
        cin >> val;
        next[i] = val + i;
        if(!fan_in[next[i]]){
            cur_possible++;
            fan_in[next[i]] = true;
        }
    }

    for(int i = 0; i < N; i++){
        if(!fan_in[i]){
            next[i] = -1;
        }
    }

    while(cur_possible != prev_possible){
        prev_possible = cur_possible;
        cur_possible = 0;
        cur = 1 - cur;

        fan_in.assign(N, false);
        for(int i = 0; i < N; i++){
            if(next[i] != -1){
                if(!fan_in[next[i]]){
                    cur_possible++;
                    fan_in[next[i]] = true;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(!fan_in[i]){
                next[i] = -1;
            }
        }    
    }

    int answer = 0;
    vector<int> loop(N, 0);
    vector<int> cycle(0);
    for(int i = 0; i < N; i++){
        if(fan_in[i] && loop[i] == 0){
            cycle.push_back(i);
            int index = next[i];

            while(index != i){
                cycle.push_back(index);
                index = next[index];
            }

            if(cycle.size() > answer){
                answer = cycle.size();
            }
            for(int j= 0; j < cycle.size(); j++){
                loop[cycle[j]] = cycle.size();
            }
        }
    }

    cout << answer;
}
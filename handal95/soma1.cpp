#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int bf(vector<int> computers, int index, int value, int H){
    if(index == computers.size()){
        return value;
    }

    int select = bf(computers, index + 1, value, H);
    if(value + computers[index] <= H){
        select = max(
            select,
            bf(computers, index + 1, value + computers[index], H)
        );
    }
    return select;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int P, N, H;
    cin >> P >> N >> H;
    vector<pair<int, int>> users; // pc num, time

    vector<vector<int>> computers(P, vector<int>());
    for(int i = 0; i < N; i++){
        int pc, time;
        cin >> pc >> time;
        if(time <= H){
            computers[pc - 1].push_back(time);
        }
    }

    for(int i = 0; i < P; i++){
        sort(computers[i].begin(), computers[i].end());
    }

    for(int i = 0; i < P; i++){
        int answer = 0;
        
        if(computers[i].size() > 0){
            answer = max(
                bf(computers[i], 1, 0, H),
                bf(computers[i], 1, computers[i][0], H)
            );
        }
        cout << (i + 1) << " " << (answer * 1000) << endl;
    }
}
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> power_pole(N);

    for(int i = 0 ; i < N; i++){
        int a, b;
        cin >> a >> b;
        power_pole[i] = {a, b};
    }

    sort(power_pole.begin(), power_pole.end());

    int answer = 0;
    vector<int> removed(N);
    for(int i = 0; i < N; i++){
        removed[i] = 1;
        for(int j = 0; j < N; j++){
            if(removed[j] + 1 > removed[i] && power_pole[i].second > power_pole[j].second){
                removed[i] = removed[j] + 1;
            }
        }
        answer = max(removed[i], answer);
    }
    cout << (N - answer) << "\n";
}

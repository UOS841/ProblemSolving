#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int N,  // The # of participants 
        M;  // The # of parties
    cin >> N >>  M;

    queue<int> q;

    int known_num;
    cin >> known_num;
    vector<bool> known_truth(N + 1, false);
    // 진실을 알고 있는 사람들
    for(int i = 0 ; i < known_num; i++){
        int person;
        cin >> person;
        known_truth.at(person) = true;
        q.push(person);
    }

    // 파티별 참석자 명단
    vector<vector<bool>> party(M + 1, vector<bool>(N + 1, false));
    for(int m = 1; m <= M; m++){
        int participants_num;
        cin >> participants_num;
        for(int i = 0 ; i < participants_num; i++){
            int person;
            cin >> person;
            party.at(m).at(person) = true;
        }
    }

    // 진실의 전파2
    while(!q.empty()){
        int person = q.front(); q.pop();
        for(int m = 1; m <= M; m++){
            if(party.at(m).at(person) == false){
                continue;
            }

            for(int n = 1 ; n <= N; n++){
                if(party.at(m).at(n) == true &&
                   known_truth.at(n) == false){
                    known_truth.at(n) = true;
                    q.push(n);
                }
            }
        }
    }

    int answer = M;
    for(int m = 1; m <= M; m++){
        for(int n = 1 ; n <= N; n++){
            if(party.at(m).at(n) == true &&
               known_truth.at(n) == true){
                answer--;
                break;
            }
        }
    }
    cout << answer;
}

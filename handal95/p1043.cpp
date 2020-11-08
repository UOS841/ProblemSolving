#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int N, M;
    cin >> N >>  M;

    vector<bool> known_truth(N + 1, false);
    vector<vector<bool>> party(M + 1, vector<bool>(N + 1, false));
    queue<int> q;

    int known_num;
    cin >> known_num;
    cout << "STEP 1 " << endl;
    for(int i = 0 ; i < known_num; i++){
        int person;
        cin >> person;
        known_truth.at(person) = true;
        q.push(person);
    }

    for(int m = 1 ; m <= M; m++){
        int participants_num;
        cin >> participants_num;
        for(int i = 0 ; i < participants_num; i++){
            int person;
            cin >> person;
            party.at(m).at(person) = true;
        }
    }

    while(!q.empty()){
        int person = q.front(); q.pop();
        for(int m = 1; m <= M; m++){
            if(party.at(m).at(person) == true){

                for(int n = 1 ; n <= N; n++){
                    if(party.at(m).at(n) == true &&
                       known_truth.at(n) == false){
                        known_truth.at(n) = true;
                        q.push(n);
                    }
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

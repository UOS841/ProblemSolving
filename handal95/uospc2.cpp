#include <iostream>
#include <vector>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> palindrom(N);
    for(int i = 0; i < N ; i++){
        cin >> palindrom[i];
    }

    // Palindrom check
    bool inc_flag = false;
    bool dec_flag = false;
    for(int i = 0; i < N/2 ; i++){
        if(palindrom[i] != palindrom[N-i-1]){
            cout << 'D';
            return 0;
        }
        if(palindrom[i] < palindrom[i+1]){
            inc_flag = true;
        }
        if(palindrom[i] > palindrom[i+1]){
            dec_flag = true;
        }
    }

    if(N >= 3){
        if(inc_flag && !dec_flag){
            cout << 1;
            return 0;
        }else if(dec_flag && !inc_flag){
            cout << 2;
            return 0;
        }
    }
    cout << 3;
}
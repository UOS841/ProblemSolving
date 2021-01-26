#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-->0){
        int M;
        cin >> M;
        double log_facto = 0.0;
        for(int i = 1; i <= M; i++){
            log_facto += log10(i);
        }
        int answer = int(log_facto) + 1;
        cout << answer << endl;
    }
}
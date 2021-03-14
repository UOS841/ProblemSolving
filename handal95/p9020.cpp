#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> primes(10001, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i < primes.size(); i++) {
        if (primes[i]) {
            for (int j = i + i; j < primes.size(); j += i) {
                primes[j] = false;
            }
        }
    }

    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        for(int i = N/2; i < N; i++){
            if(primes[i] &&  primes[N - i]){
                cout << (N - i) << " " << i << endl;
                break;
            }
        }
    }
}
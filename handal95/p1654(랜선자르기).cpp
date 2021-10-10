#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    
    int K, N;
    cin >> K >> N;
    
    vector<long> lines;
    lines.resize(K);
   
    for (int i = 0; i < K; i++){
        cin >> lines[i];
    }

    long long max = 0; 
    long long left = 0;
    long long right = LLONG_MAX;
    while (left <= right){
        long long mid = (left + right) / 2;
        int answer = 0;
 
        for (int line : lines){
            answer += (line / mid);            
        }
 
        if (answer >= N){
            left = mid + 1;
            if (mid > max){
                max = mid;
            }
        }
        else if(answer < N){
            right = mid - 1;            
        }
    }
    cout << max;
    return 0;
}
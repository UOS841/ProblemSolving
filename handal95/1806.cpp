#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N;
    long long S;
    cin >> N >> S;
    vector<int> sequence(N, 0);

    int answer = N + 1;
    for(int i = 0; i < N; i++){
        cin >> sequence[i];
    }

    int to = 0;
    int from = 0;
    long long sum = sequence[0];
    while(from <= to && to < N){
        if(sum < S){
            sum += sequence[++to];
        }else if(sum == S){
            answer = min(answer, to - from + 1);
            sum += sequence[++to];
        }else if(sum > S){
            answer = min(answer, to - from + 1);
            sum -= sequence[from++];
        }
    }
    cout << (answer == N + 1 ? 0 : answer);
}
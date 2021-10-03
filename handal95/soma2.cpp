#include <iostream>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, M, E;
    cin >> N >> M >> E;

    vector<int> peanuts(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> peanuts[i];
    }

    int answer = peanuts[N] + 1;
    for(int i = 1; i <= N - M; i++){
        int current = 0;
        if(peanuts[i] <= E && E <= peanuts[i + M - 1]){
            current = peanuts[i + M - 1] - peanuts[i];
        } else {
            if(E > peanuts[i + M - 1]){
                current += E - peanuts[i];
            } else if(E < peanuts[i]) {
                current += peanuts[i + M - 1] - E;
            }
        }
        answer = min(answer, current);
    }
    cout << answer;
}
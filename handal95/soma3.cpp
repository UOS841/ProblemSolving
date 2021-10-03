#include <iostream>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> steps(N);
    for(int i = 0; i < N; i++){
        cin >> steps[i];
    }

    int answer = -1;
    vector<bool> is_visited(N, false);
    for(int start = 0; start < 3; start++){
        is_visited.assign(N, false);
        int score = 1;
        int current = start;
        while(!is_visited[current]){
            score += 1;
            is_visited[current] = true;
            current = current + steps[current];
        }
        answer = max(score, answer);
    }
    cout << answer;
}
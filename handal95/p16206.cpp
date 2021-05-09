#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cut_cake(priority_queue<int, vector<int>, greater<int>> pq, int& M){
    int answer = 0;
    while(!pq.empty() && M > 0){
        int cur = pq.top(); pq.pop();

        if(cur == 10){
            answer++;
        } else if (cur > 10 && M > 0){
            M--;
            answer++;
            if(cur == 20){
                answer++;
            } else {
                pq.push(cur - 10);
            }
        }
    }
    
    while(!pq.empty()){
        if(pq.top() == 10){
            answer++;
        }
        pq.pop();
    }

    return answer;
}

int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int>> pq_10;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < N; i++){
        int cakes;
        cin >> cakes;

        if(cakes % 10 == 0){
            pq_10.push(cakes);
        } else {
            pq.push(cakes);
        }
    }

    int answer = 0;
    answer += cut_cake(pq_10, M);
    answer += cut_cake(pq, M);

    cout << answer;
}
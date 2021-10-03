#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int K, N;
int answer = 2147483647;
vector<int> chapter;
vector<int> left_time;

void dfs(int person, int chap, int total){
    int val = 0;
    int count = 0;
    if(person == N - 1){
        total = total + left_time[chap];

        if(total < answer){
            answer = total;
        }
        return;
    }


    int left_person = N - person - 1;
    for(int ch = chap; ch < K - left_person; ch++){
        count++;
        val += chapter[ch];

        if(total + (count*val) > answer)
            break;
        dfs(person+1, ch+1, total + (count*val));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> K >> N;
    chapter.resize(K);
    left_time.resize(K+1, 0);

    int value = 0;
    for(int i = 0; i < K; i++){
        cin >> chapter[i];
        value += chapter[i];
    }
    answer = N * value;

    int left_count = 0;
    int left_value = 0;
    for(int i = K-1; i>=0; i--){
        left_count++;
        left_value += chapter[i];
        left_time[i] = left_count * left_value;
    }

    dfs(0, 0, 0);
    cout << answer;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> sum;
    sum.push_back(0);

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int num = 2; num <= N; num++){
        if(!is_prime[num]){
            continue;
        }

        for(int next_num = 2 * num; next_num <= N;next_num += num){
            is_prime[next_num] = false;
        }

        sum.push_back(sum.back() + num);
    }

    int answer = 0;
    for(int end = 0, start = 0; end < sum.size();){
        int partial_sum = sum[end] - sum[start];
        if(partial_sum == N){
            answer++;
            end++;
        } else if (partial_sum < N){
            end++;
        } else if (partial_sum > N){
            start++;
        }
    }

    cout << answer << endl;
}
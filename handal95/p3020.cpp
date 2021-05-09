#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, H;
    cin >> N >> H;

    vector<int> bottom(N / 2), top(N / 2);
    for (int i = 0; i < N / 2; i++){
        cin >> bottom[i] >> top[i];
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int answer = N;
    int count = 1;
    for (int i = 1; i <= H; i++){
        int result = (bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin()) ) +
                   + (   top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin()));

        if (answer == result){
            count++;
        }
        else if (answer > result){
            answer = result;
            count = 1;
        }
    }

    cout << answer << " " << count;
}
#include <iostream>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    int M;
    cin >> N;
    cin >> M;
    vector<int> numbers(N + 1);
    vector<int> sum(N + 1);
    for(int i = 1; i <= N; i++){
        int value;
        cin >> numbers[i];
        sum[i] = numbers[i] + sum[i - 1];
    }

    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        cout << sum[to] - sum[from - 1] << "\n";
    }
}
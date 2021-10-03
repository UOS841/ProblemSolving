#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

vector<int> values;

int binary(int N, int depth, int left, int right){
    if(N == pow(2, depth)){
        
    }
    // right

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    values.resize(N);
    for(int i = 0; i < N; i++){
        cin >> values[i];
    }

    int answer = max(
        binary(N, 1, 0, N/2 - 1),
        binary(N, 1, N/2, N - 1)
    );
    cout << answer;

}
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long MAX = INTMAX_MIN;
long long MIN = INTMAX_MAX;

void bf(vector<int> sequences, long long val, int i, vector<int> op) {
    if(i == sequences.size()) {
        MAX = max(MAX, val);
        MIN = min(MIN, val);
        return ;
    }

    if(op[0] > 0)  {
        bf(sequences, val + sequences[i], i + 1, {op[0]-1, op[1], op[2], op[3]});
    }
    if(op[1] > 0)  {
        bf(sequences, val - sequences[i], i + 1, {op[0], op[1]-1, op[2], op[3]});
    }
    if(op[2] > 0)  {
        bf(sequences, val * sequences[i], i + 1, {op[0], op[1], op[2]-1, op[3]});
    }
    if(op[3] > 0)  {
        bf(sequences, val / sequences[i], i + 1, {op[0], op[1], op[2], op[3]-1});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int N;
	cin >> N;
    vector<int> sequences(N);
    for(int i = 0; i < N; i++){
        cin >> sequences[i];
    }

    vector<int> operations(4);
    for(int i = 0; i < 4; i++){
        cin >> operations[i];
    }

    bf(sequences, sequences[0], 1, operations);
    
    cout << MAX << "\n" << MIN;
}

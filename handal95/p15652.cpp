#include <iostream>
#include <vector>


using namespace std;


int N, M;
void dfs(int depth, int index, vector<int> sequence){
    if(sequence.size() >= M){
        for(int i = 0; i < sequence.size(); i++){
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = index; i <= N; i++){
        sequence.push_back(i);
        dfs(depth + 1, i, sequence);
        sequence.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> sequence(0);

    dfs(0, 1, sequence);
}
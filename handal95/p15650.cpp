#include <iostream>
#include <vector>

using namespace std;

int N, M;
void dfs(int idx, int depth, vector<int> selected){
    if(depth == M){
        for(int i = 0; i < selected.size(); i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    if(idx > N){
        return;
    }

    selected.push_back(idx);
    dfs(idx + 1, depth + 1, selected);
    selected.pop_back();
    dfs(idx + 1, depth, selected);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        vector<int> selected(1, i);

        dfs(i + 1, 1, selected);
    }
}
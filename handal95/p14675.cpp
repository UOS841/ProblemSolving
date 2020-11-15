#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> nodes;

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    nodes.resize(N+1, vector<int>());
    for(int i = 1; i < N; i++){
        int A, B;
        cin >> A >> B;
        nodes[A].push_back(B);
        nodes[B].push_back(A);
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int A, B;
        cin >> A >> B;

        if(A == 1){
            cout << (nodes[B].size() >= 2 ? "yes\n" : "no\n");
        }
        else{
            cout << "yes\n";
        }
    }
}
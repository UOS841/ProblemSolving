#include <iostream>
#include <vector> 

using namespace std; 

vector<int> root;

int find(int x){
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a < b){
        root[b] = a;
    } else {
        root[a] = b;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    root.resize(N + 1, 0);

    int is_connected;
    for(int i = 1; i <= N; i++){
        root[i] = i;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> is_connected; 
            if(is_connected){
                merge(i, j);
            }
        }
    }

    int root;
    cin >> root;
    root = find(root);
    for(int i = 1; i < M; i++){
        int city;
        cin >> city; 
        if(root != find(city)){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
} 
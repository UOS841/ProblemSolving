#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int index;
    int child_left;
    int child_right;
};

vector<Node> nodes;

int main(){
    int N;
    cin >> N;
    nodes.resize(N+1);

    int U, V;
    for(int i = 1 ; i < N;i++){
        cin >> U >> V;

        nodes[i].index = i;
        nodes[i].child_left = U;
        nodes[i].child_right = V;
    }
}
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node{
    int index;
    Node* parent;
    vector<Node> childs;
} Node;

int main(){
    int N;
    cin >> N;
    vector<Node> nodes(N + 1);
    for(int i = 0; i <= N; i++){
        nodes[i] = { i, &nodes[0], vector<Node>() };
    }

    for(int i = 1; i < N; i++){
        int parent, child;
        cin >> parent >> child;
        nodes[parent].childs.push_back(nodes[child]);
        nodes[child].parent = &nodes[parent];
    }

    for(int i = 1; i <= N; i++){
        cout << i << "th parent " << nodes[i].parent->index << endl;
    }
}
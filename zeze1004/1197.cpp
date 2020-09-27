#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> parent;
vector<int> weight;

// 부모가 같은지 판단하는 함수
bool sameParent(int node1, int node2) {
    /*if (node1 == node2) {
        return false;
    } 
    else return true;
    */
    node1 = findParent(node1);    //노드 x의 부모 찾기
    node2 = findParent(node2);    // 노드 y의 보모 찾기
    if(node1==node2) 
        return true;
    else
        return false;
}

int findParent(int node) {
    if(parent[node]==node) return node;
    else return parent[node] = findParent(parent[node]);   
}

void union(int node1, int node2) {
    parent[node1] = findParent(node1); // x 부모를 찾고
    parent[node2] = findParent(node2); // y 부모를 찾고
    if( parent[node1] != parent[node2] ){   // 두 노드의 부모가 다르다면
        parent[parent[node2] = parent[node1];  // 어는 한 쪽 노드의 부모를 연결되는 다른 한쪽 노드로 설정
    }
}
int Sort(int E, vector<int> &v){
    for(int i = 0; i < E; i++) {
        return v = sort(v[i]);
    }
}

int main() { 
    int V,E;    //정점의 개수, 간선의 개수
    int A,B,C;  // A(노드) - C(가중치) -> B(노드)
    
    int node = 0;
    cin >> V >> " " >> E >> '\n';
    for ( int i = 0; i < E; i++) {
        cin >> A >> " " >> B >> " " >> C >> '\n';
        parent.push_back(A);
        parent.push_back(B); // 2n+1
        weight.push_back(C);     
    }
    // ?ㅅ? 이걸 이제 어떻게 하지,,,
    // weight 오름차순에 따라 parent 배열 바꾸기
    Sort(E, weight);


    // 부모 찾는 함수
    for(int n = 0; n < E; n++) {
        findParent(parent[n]); 
    }

    // 부모가 다르면 서로
    for(int n = 0; n < E; n++){
        bool sameParent(parent[2*n], parent[(2*n)+1]);
        if (sameParent == true) {
            // 각자의 부모를 서로로?
            void union(parent[2*n], parent[(2*n)+1])
            int weight =+ weight[n];           
            }
        }
    }
    cout << weight;

  

    return 0;
}
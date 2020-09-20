#include <iostream>
#include <vector>
using namespace std;
 
vector<int>root;
 
int find(int node) {
    if (root[node] == node)
        return node;
    else
        return root[node] = find(root[node]);
}
 
void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    root[pb] = pa;
}
 
int main() {
    // 건호 교수님이 말한 빨리 출력하기
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num, calc;
    cin >> num >> calc;
 
    for (int i = 0; i <= num; i++)
        root.push_back(i);
 
    int cmd, a, b;
    for (int i = 0; i < calc; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            uni(a, b);
        }
        else {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}

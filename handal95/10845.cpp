#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> q;
    string str;
    int value;
    for(int i = 0; i < N; i++){
        cin >> str;
        if(str == "push"){
            cin >> value;
            q.push(value);
        } else if (str == "pop"){
            if (q.empty()){
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (str == "size"){
            cout << q.size() << "\n";
        } else if (str == "empty"){
            cout << (q.empty() ? "1" : "0") << "\n";
        } else if (str == "front") {
            cout << (q.empty() ? -1 : q.front()) << "\n";
        } else if (str == "back") {
            cout << (q.empty() ? -1 : q.back()) << "\n";
        }
    }
}
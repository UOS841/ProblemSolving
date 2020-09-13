#include <iostream>
#include <queue>

using namespace std;


int main(){
    int N;
    cin >> N;

    queue<int> que;
    for(int i = 1 ; i <= N ; i++){
        que.push(i);
    }

    while(que.size()>1){
        que.pop();
        
        que.push(que.front());
        que.pop();
    }
    cout << que.front() << endl;
    que.pop();

    return 0;
}
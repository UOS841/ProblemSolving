#include <iostream>
#include <vector>

using namespace std;

int main(){
    int B;
    int N;

    cin >> B >> N;
    int val;
    for(int i = 0; i < N; i++){
        cin >> val;
        B -= val;
    }
    if(B>=40){
        cout << "possible";
    }else{
        cout << "impossible";
    }
}
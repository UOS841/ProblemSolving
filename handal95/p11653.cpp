#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int num = N;
    for(int divide = 2; divide * divide <= num; divide++){
        while(num % divide == 0){
            cout << divide << "\n";
            num /= divide;
        }
    }
    if(num > 1){
        cout << num << "\n";
    }
}
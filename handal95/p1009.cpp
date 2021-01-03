#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    int loop[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
    while(T-- > 0){
        int A, B;
        cin >> A >> B;
        A = A % 10;
        B = (B % loop[A] == 0) ? loop[A] : B % loop[A];

        int answer = ((int)pow(A, B) % 10 == 0) ? 10 : ((int)pow(A, B) % 10);
        cout << answer << endl;
    }
}
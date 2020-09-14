#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    string AB = to_string(A)+to_string(B);
    string CD = to_string(C)+to_string(D);

    // stoi: string to int
    // stoll: string to long long => 범위값이 커서 stoll 써야 함
    cout << stoll(AB) + stoll(CD);
    
    return 0;
}
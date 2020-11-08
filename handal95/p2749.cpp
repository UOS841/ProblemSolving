#include<iostream>
#include<vector>

using namespace std;
 
int main() {
    long long n;
    cin >> n;
    vector<int> fibo(1500000);
    fibo.at(0) = 0;
    fibo.at(1) = 1;
    for(int i = 0; i <fibo.size()-2; i++){
        fibo.at(i+2) = (fibo.at(i) + fibo.at(i+1)) % 1000000;
    }
    cout << fibo.at(n%1500000) << endl;
}
